#ifndef RANET_BLOCKINGQUEUE_H
#define RANET_BLOCKINGQUEUE_H
#include <deque>
#include "Mutex.h"
#include "Condition.h"

template <class T>
class BlockingQueue
{
public:
    BlockingQueue():_cond(_mutex)
    {}
    void put(const T& one){
        MutexLockGuard lock(_mutex);
        _queue.push_back(one);
        _cond.notify();
    }

    T take(){
        MutexLockGuard lock(_mutex);
        while(_queue.empty())
        {
            _cond.wait();
        }
        T front = _queue.front();
        _queue.pop_front();
        return front;
    }
private:
    std::deque<T> _queue;
    MutexLock _mutex;
    Condition _cond;
};

#endif //RANET_BLOCKINGQUEUE_H
