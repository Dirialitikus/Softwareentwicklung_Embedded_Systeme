//
// Created by kaane on 26.11.2022.
//

#ifndef EMBEDDED_PRAK_CNAMEDSEMAPHORE_H
#define EMBEDDED_PRAK_CNAMEDSEMAPHORE_H


#include <semaphore.h>


// class encapsulating a named semaphore with just the functionality we need
class CNamedSemaphore {

public:

    // create and destroy the semaphore
    // @name - name of the semaphore being created in /run/shm
    // @value - initial value of the semaphore
    CNamedSemaphore(const char *name, int value);
    ~CNamedSemaphore();

    // increment value of the semaphore (release if value is zero)
    void increment(void);
    // decrement value of the semaphore (wait blocked if value is zero)
    void decrement(void);

    // return the current value of the semaphore
    int value(void);

    void setErrorText(int);

private:
    sem_t       *semaphore;
    // what do I need to remember in the object being required later on?
    // Add such information as additional private variables here
    const char *remember_my_name;
    pid_t       remember_my_creator;

    // print text with ERRNO and exit process
    void exitproc(const char *text, int);

    // enforce using constructor with parameters
    CNamedSemaphore();
};


#endif //EMBEDDED_PRAK_CNAMEDSEMAPHORE_H
