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

using namespace std;
Motion* motion;

CSensorTag tag;
Motion k;

uint dataLaps = 100;
#define NUMBER_OF_THREADS  2
pthread_mutex_t mutex;
pthread_t filler, deleter;
bool threadLock = false;

// valid states for our two processes, we use the impicit ordering of values
// by an enum starting with the value 1
enum EProc_State {
    STATE_ACTIVE_CHILD = 1,
    STATE_ACTIVE_PARENT,
    STATE_TERMINATE
};

#define NUMBER_OF_LOOPS 5
int counter = 0;

unsigned int m_size;
int shm_fd;

const char sem_name1[] = "/semaphore";
const char sem_name2[] = "/state";

CNamedSemaphore semaphore(sem_name1, 1);
CNamedSemaphore state(sem_name2, STATE_ACTIVE_CHILD);


void printAccScopeData(Accelerometer s);
void printGyroScopeData(Gyroscope m);

struct MT{
    Motion_t* motion;
    CSensorTag* tag;
};


void* fillWithData(void* motion){
    MT* mt = (MT*) motion;
    Motion_t* m = mt->motion;
    CSensorTag* t = mt->tag;

    for(u_int i = 0; i<NUMBER_OF_LOOPS; i++) {
        pthread_mutex_lock(&mutex);
        while(true) {
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
        pthread_mutex_lock(&mutex);
        while(true){
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
        if(!parent){
            //maybe do other stuff here
            semaphore.decrement();//critical area start
            counter++;
            if (state.value() == STATE_ACTIVE_CHILD){
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
            if(state.value() == STATE_TERMINATE) return;
            semaphore.increment();
        }
    }
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
    pthread_create(&filler, NULL, fillWithData, (void *)&mt);
    pthread_create(&deleter, NULL, fillWithZero, (void*)&k);
    pthread_join(filler, NULL);
    pthread_join(deleter, NULL);

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
        pingpong(!isParent);
        std::cout << "CHILD IS EXECUTING" << std::endl;
        _exit(EXIT_SUCCESS);
    }else{
        pingpong(isParent);
        int status;
        wait(&status);
        std::cout << "PARENT IS EXECUTING" << std::endl;
        exit(EXIT_SUCCESS);
    }

    return 0;
}

void printGyroScopeData(Gyroscope m){
    std::cout << "Gyroscope x:" << m.x << "\tGyroscope y:" << m.y << "\tGyroscope z:" << m.z << std::endl;
}

void printAccScopeData(Accelerometer s){
    std::cout << "Accelerometer x:" << s.x << "\tAccelerometer y:" << s.y << "\tAccelerometer z:" << s.z << std::endl;
}

int main() {
    execute();

    return 0;
}


