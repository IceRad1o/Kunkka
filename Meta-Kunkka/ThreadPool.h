#ifndef RANET_THREADPOOL_H
#define RANET_THREADPOOL_H

#include "Declare.h"
#include "BlockingQueue.h"
#include "Task.h"
#include "IRun.h"
#include <vector>

class ThreadPool : public IRun0
{
public:
    ThreadPool() = default;
    void start(int numThreads);
    void addTask(Task& task);
    virtual void run0();
private:
    void runInThread();
    BlockingQueue<Task> _tasks;
    std::vector<Thread*> _threads;
};

#endif //RANET_THREADPOOL_H
