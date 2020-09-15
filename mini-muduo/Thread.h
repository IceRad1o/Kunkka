#ifndef RANET_THREAD_H
#define RANET_THREAD_H
#include "Declare.h"
#include "Task.h"
#include <pthread.h>

class Thread{
public:
    Thread(Task& task);
    void start();
    void run();
    pid_t gettid();
private:
    Task _task;
};

#endif //RANET_THREAD_H
