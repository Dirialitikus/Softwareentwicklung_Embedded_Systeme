#include <iostream>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/unistd.h>
#include "CNamedSemaphore.h"
#include <semaphore.h>


void CNamedSemaphore::setErrorText(int err){
    if (err ==  ENOMEM) this->exitproc("Insufficient memory", err);
    else if (err == EMFILE) this->exitproc("The per-process limit on the number of open file descriptors has been reached.", err);
    else if (err == EACCES) this->exitproc("Only Creator can unlink semaphore", err);
    else if (err == ENAMETOOLONG) this->exitproc("Name was to long", err);
    else if (err ==  ENOENT) this->exitproc("No Semaphore with the given name", err);
    else if (err == EEXIST) this->exitproc("No Semaphore with the given name", err);
    else if ( err == EINVAL) this->exitproc("value was greater than SEM_VALUE_MAX. | name consists of just / followed by no other characters.", err);
    else this->exitproc("", err);
}

using namespace std;

// construct a new named semaphore
// @name - name of the semaphore being created in /run/shm
// @value - initial value of the semaphore
CNamedSemaphore::CNamedSemaphore(const char *name, int value) {
    semaphore = sem_open(name, O_CREAT, S_IRUSR | S_IWUSR, value);
    if(this->semaphore == SEM_FAILED){
        setErrorText(errno);
    }
    this->remember_my_name = name;
    this->remember_my_creator = getpid();
}

// deconstruct the semaphore
// question:
// How do we delete the semaphore by the last process only?
CNamedSemaphore::~CNamedSemaphore() {
    if((sem_close(semaphore) == -1)){
        int statusFailedToClose = errno;
        setErrorText(statusFailedToClose);
    }
    if(this->remember_my_creator == getpid()){
        if (sem_unlink(this->remember_my_name) == -1) {
            int statusFailedToUnlink = errno;
            setErrorText(statusFailedToUnlink);
        }
    }else setErrorText(0);

}


void CNamedSemaphore::increment() {
    if(sem_post(semaphore) == -1){
        int statusPost = errno;
        setErrorText(statusPost);
    }
}


void CNamedSemaphore::decrement() {
    if(sem_wait(semaphore) == -1){
        int statusWait = errno;
        setErrorText(statusWait);
    }
}


int CNamedSemaphore::value() {
    int val;
    if(sem_getvalue(semaphore, &val) == -1){
        int err = errno;
        setErrorText(errno);
        return 0;
    }else return val;

}


// helper function to display errors and terminate our
// process as a very simple error handling mechanism
void CNamedSemaphore::exitproc(const char *text, int err) {

    cout << text;
    switch (err) {
        case EACCES:
            cerr << "EACCES";
            break;
        case EEXIST:
            cerr << "EEXIST";
            break;
        case EINVAL:
            cerr << "EINVAL";
            break;
        case EMFILE:
            cerr << "EMFILE";
            break;
        case ENAMETOOLONG:
            cerr << "TOOLNG";
            break;
        case ENOENT:
            cerr << "ENOENT";
            break;
        case ENOMEM:
            cerr << "ENOMEM";
            break;
        case EOVERFLOW:
            cerr << "EOVERFLOW";
            break;
        default:
            cerr << "UNKNWN";
    }
    cout << endl;
    exit(1);
}
