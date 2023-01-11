// File     sync_proc.h
// Version  1.0
// Author   Prof. Jens-Peter Akelbein and Kaan Evlende
// Comment  Softwareentwicklung fuer Embedded Systeme - Exercise 3

#include <iostream>
#include "CNamedSemaphore.h"
#include "SensorTag/SensorTag.h"
#include <stdlib.h>
#include <sys/unistd.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <cstring>
#include <pthread.h>
#include "CCommQueue.h"
#include <arpa/inet.h>

#define SHM_NAME        "/estSHM"
#define QUEUE_SIZE      2
#define NUM_MESSAGES    500
#define NUMBER_OF_LOOPS 5
#define NUMBER_OF_THREADS  2
#define MESSAGE_TYPE_REQUEST 1
#define MESSAGE_TYPE_RESPONSE 2

struct PackedData {
    Motion_t motion;
    UInt64 time;
};
typedef struct PackedData PackedData_t;

struct MT{
    Motion_t* motion;
    CSensorTag* tag;
};

// valid states for our two processes, we use the impicit ordering of values
// by an enum starting with the value 1
enum EProc_State {
    STATE_ACTIVE_CHILD = 1,
    STATE_ACTIVE_PARENT,
    STATE_TERMINATE
};

Motion* motion;
CSensorTag tag;
Motion k;

pthread_mutex_t mut;
pthread_mutex_t mutex;
pthread_t filler, deleter;
uint dataLaps = 100;
bool threadLock = false;
int counter = 0;

unsigned int m_size;
int shm_fd;
int shm_fd_ipc;

const char sem_name1[] = "/semaphore";
const char sem_name2[] = "/state";

CNamedSemaphore semaphore(sem_name1, 1);
CNamedSemaphore state(sem_name2, STATE_ACTIVE_CHILD);

void printAccScopeData(Accelerometer s);
void printGyroScopeData(Gyroscope m);

//Funktioniert nur mit flots die 32Bit haben
float ntohf(uint32_t net32){
    union {
        float f;
        uint32_t u;
    } value;
    value.u = ntohl(net32);
    return value.f;
}
float htonf(uint32_t net32){
    union {
        float f;
        uint32_t u;
    } value;
    value.u = htonl(net32);
    return value.f;
}

void* fillWithData(void* motion){
    MT* mt = (MT*) motion;
    Motion_t* m = mt->motion;
    CSensorTag* t = mt->tag;

    for(u_int i = 0; i<NUMBER_OF_LOOPS; i++) {

        while(true) {
            pthread_mutex_lock(&mutex);
            if (!threadLock) {
                auto start = std::chrono::high_resolution_clock::now();
                *m = t->getMotion();
                printGyroScopeData(m->gyro);
                printAccScopeData(m->acc);
                auto end = std::chrono::high_resolution_clock::now() - start;
                threadLock = true;
                long long elapsedTimeMS = std::chrono::duration_cast<std::chrono::microseconds>(end).count();

                std::cout << "elapsed time: " << elapsedTimeMS << "ms"
                          << "\nThread for Filling Data Task Number: " << i << std::endl
                          << "-------------------------------------------" << std::endl;
                break;
            }
        }
        //usleep(100);
        pthread_mutex_unlock(&mutex);
    }
    return 0;


}
void* fillWithZero(void* motion){
    Motion_t* mot = (Motion_t*) motion;

    for(u_int i = 0; i<NUMBER_OF_LOOPS; i++) {

        while(true){
            pthread_mutex_lock(&mutex);
            if (threadLock) {
                auto start = std::chrono::high_resolution_clock::now();
                memset(mot, 0, sizeof(*mot));
                printGyroScopeData(mot->gyro);
                printAccScopeData(mot->acc);
                threadLock = false;
                auto end = std::chrono::high_resolution_clock::now() - start;
                long long elapsedTimeMS = std::chrono::duration_cast<std::chrono::microseconds>(end).count();

                std::cout << "elapsed time: " << elapsedTimeMS
                          << "ms" << "\nThread for Filling Zero Task Number: " << i <<
                          std::endl << "-------------------------------------------" << std::endl;
                break;
            }
        }
        pthread_mutex_unlock(&mutex);
    }
    return 0;
}

void pingpong(bool parent) {
    while(counter < NUMBER_OF_LOOPS) {
        pthread_mutex_lock(&mutex);
        if(!parent){
            //maybe do other stuff here
            semaphore.decrement();//critical area start

            if (state.value() == STATE_ACTIVE_CHILD){
                counter++;
                std::cout << "Ping" << " Data From Child:"  <<
                          "Accelerometer x:" << motion->acc.x << "\tAccelerometer y:" << motion->acc.y << "\tAccelerometer z:" << motion->acc.z << std::endl;
                if(counter >= NUMBER_OF_LOOPS) state.increment();
                state.increment();//switch to parent state
            }
            semaphore.increment();//criticial area end
        }

        if(parent) {
            semaphore.decrement();
            //maybe do other stuff here
            if (state.value() == STATE_ACTIVE_PARENT) {
                *motion = tag.getMotion();
                std::cout << "Pong" << std::endl;
                state.decrement();
            }
            if(state.value() >= STATE_TERMINATE) return;
            semaphore.increment();
        }

        pthread_mutex_unlock(&mutex);
    }
}

void IPC_with_shm(){

    shm_fd_ipc = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    size_t size_of_mq = sizeof(CBinarySemaphore) + sizeof(CCommQueue);//Eventeull nicht richtig weil ich eine queue von 10 brauche
    ftruncate(shm_fd_ipc, size_of_mq);
    void* shm_ptr = mmap(nullptr, size_of_mq, PROT_WRITE, MAP_SHARED, shm_fd_ipc, 0);

    CBinarySemaphore* semaphore = new (shm_ptr) CBinarySemaphore;
    CCommQueue* message_queue = new (semaphore + sizeof(semaphore)) CCommQueue(QUEUE_SIZE, *semaphore);

    pid_t id = fork();
    if(id == 0){
        std::cout << "CHILD IS RUNNING" << std::endl;
        //child
        int i = 0;
        while(i<NUM_MESSAGES){
            CMessage m(CMessage::MessageType::Internal_App_Type);
            PackedData_t p;
            Motion mtt = tag.getMotion();
            mtt.acc.x += i;
            mtt.acc.y += i;
            mtt.acc.z += i;
            mtt.gyro.x += i;
            mtt.gyro.y += i;
            mtt.gyro.z += i;
            p.motion = mtt;
            p.time = std::clock();
            m.setSenderID(getpid());
            m.setReceiverID(getppid());
/*          m.setParam1(NULL);
            m.setParam2(NULL);
            m.setParam3(NULL);
*/          m.setParam4((Int8*)&p, sizeof(p));
            message_queue->add(m);
            i++;
        }
        semaphore->give();

        std::cout << "CHILD IS EXECUTING" << std::endl;
        _exit(EXIT_SUCCESS);
    }
    else if(id > 0){
        std::cout << "PARENT IS RUNNING" << std::endl;
        int i = 0;
        while(i<NUM_MESSAGES){
            semaphore->take();
            while(message_queue->getNumOfMessages() > 0){
                cout << std::endl << message_queue->getNumOfMessages();
                CMessage msg;
                message_queue->getMessage(msg);
                PackedData_t* pd = (PackedData_t*)msg.getParam4();
                Motion mtt = pd->motion;
                auto a_time = pd->time;
                auto e_time = std::clock();
                auto time = e_time - a_time;
                std::cout << "Message Typ:" << msg.getMessageType() << "  Message Sender:" << msg.getSenderID() << "  Receiver ID:" << msg.getReceiverID() << " ";

                printAccScopeData(mtt.acc);
                printGyroScopeData(mtt.gyro);
                std::cout << " vebrauchte Zeit, bis Message aus der Queue gelese wurde:" << time << std::endl;
                i++;
            }
        }
        int status;
        wait(&status);

    }
    else{
        std::cerr << "Fork didnt work" << std::endl;
    }

    shmctl(shm_fd_ipc, IPC_RMID, NULL);
    semaphore = NULL;
    message_queue = NULL;

}

int execute(){
    //check if semaphores are still up, if -> unlink
    sem_unlink(sem_name1);
    sem_unlink(sem_name2);

    //IPC with sharedMemory, only for fork() needed
    m_size = sizeof(Motion);
    shm_fd = shm_open("sensordaten", O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, m_size);
    motion = (Motion*) mmap(nullptr, m_size, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    tag = CSensorTag();
    tag.setAddr("24:71:89:E8:33:83");
    MT mt = {&k, &tag};
    if (tag.initRead() == 0) {
        tag.writeMovementConfig();
        tag.disconnect();
    }


    //pThread
    // pthread_create(&filler, NULL, fillWithData, (void *)&mt);
    //pthread_create(&deleter, NULL, fillWithZero, (void*)&k);


    // pthread_join(deleter, NULL);
    //pthread_join(filler, NULL);

    k.acc.x = 0;
    k.acc.y = 0;
    k.acc.z = 0;
    k.gyro.x = 0;
    k.gyro.y = 0;
    k.gyro.z = 0;

    //multi_process
    bool isParent = true;
    int id = fork();

    if(id == 0){
        sleep(1);
        pingpong(!isParent);
        std::cout << "CHILD IS EXECUTING" << std::endl;
        _exit(EXIT_SUCCESS);
    }else if (id > 0){
        pingpong(isParent);
        int status;
        wait(&status);
        std::cout << "PARENT IS EXECUTING" << std::endl;
        //exit(EXIT_SUCCESS);
    }
    else{
        std::cerr << "Fork didnt work" << std::endl;
    }
}

void printGyroScopeData(Gyroscope m){
    std::cout << "Gyroscope x:" << m.x << "\tGyroscope y:" << m.y << "\tGyroscope z:" << m.z << std::endl;
}

void printAccScopeData(Accelerometer s){
    std::cout << "Accelerometer x:" << s.x << "\tAccelerometer y:" << s.y << "\tAccelerometer z:" << s.z << std::endl;
}

int main() {
    //execute();
    IPC_with_shm();

    std::cout << "Parent process still alive" << std::endl;
    return 0;
}


