#include "TimerQueue.h"

#include<sys/time.h>
#include<unistd.h>
#include <sys/timerfd.h>
#include <cinttypes>
#include <stdio.h>
#include <strings.h>

#include "TimerQueue.h"
#include "Channel.h"
#include "EventLoop.h"
#include "Timestamp.h"
#include "Task.h"

#include <iostream>

TimerQueue::TimerQueue(EventLoop *pLoop)
        :_timerfd(createTimerfd())
        ,_pLoop(pLoop)
        ,_timerfdChannel(new Channel(_pLoop, _timerfd)) // Memory Leak !!
{
    _timerfdChannel->setCallBack(this);
    _timerfdChannel->enableReading();
}

TimerQueue::~TimerQueue()
{
    ::close(_timerfd);
}

void TimerQueue::run2(const std::string &str, void *timer) {
    if(str == "addtimer"){
        doAddTimer((Timer*)timer);
    }
    else if(str == "canceltimer"){
        doCancelTimer((Timer*)timer);
    }
    else{}
}

void TimerQueue::doAddTimer(Timer* pTimer)
{
    bool earliestChanged = insert(pTimer);
    if(earliestChanged)
    {
        resetTimerfd(_timerfd, pTimer->getStamp());
    }
}

void TimerQueue::doCancelTimer(Timer* pTimer)
{
    Entry e(pTimer->getId(), pTimer);
    TimerList::iterator it;
    for(it = _timers.begin(); it != _timers.end(); ++it)
    {
        if(it->second == pTimer)
        {
            _timers.erase(it);
            break;
        }
    }
}

long TimerQueue::addTimer(IRun0* pRun, Timestamp when, double interval)
{
    Timer* pTimer = new Timer(when, pRun, interval); //Memory Leak !!!
    std::string str("addTimer");
    Task task(this,str,pTimer);
    _pLoop->queueLoop(task);
    return (long)pTimer;
}

void TimerQueue::cancelTimer(long timerId)
{
    Timer* pCancel = (Timer*)(timerId);
    std::string str("canceltimer");
    Task task(this, str, pCancel);
    _pLoop->queueLoop(task);
}

void TimerQueue::handleRead()
{
    Timestamp now(Timestamp::now());
    readTimerfd(_timerfd, now);

    std::vector<Entry> expired = getExpired(now);
    std::vector<Entry>::iterator it;
    for(it = expired.begin(); it != expired.end(); ++it)
    {
        it->second->timeout();
    }
    reset(expired, now);
}

void TimerQueue::handleWrite()
{}

int TimerQueue::createTimerfd()
{
    int timerfd = ::timerfd_create(CLOCK_MONOTONIC,
                                   TFD_NONBLOCK | TFD_CLOEXEC);
    if(timerfd < 0)
    {
        std::cout << "failed in timerfd_create\n" ;
    }
    return timerfd;
}

std::vector<TimerQueue::Entry> TimerQueue::getExpired(Timestamp now)
{
    std::vector<Entry> expired;
    Entry sentry(now, reinterpret_cast<Timer*>(UINTPTR_MAX));
    TimerList::iterator end = _timers.lower_bound(sentry);
    copy(_timers.begin(), end, back_inserter(expired));
    _timers.erase(_timers.begin(), end);
    return expired;
}

void TimerQueue::readTimerfd(int timerfd, Timestamp now)
{
    uint64_t howmany;
    ssize_t n = ::read(timerfd, &howmany, sizeof(howmany));
    if (n != sizeof(howmany))
    {
        std::cout << "Timer::readTimerfd() error \n";
    }
}

void TimerQueue::reset(const std::vector<Entry>& expired, Timestamp now)
{
    std::vector<Entry>::const_iterator it;
    for(it = expired.begin(); it != expired.end(); ++it)
    {
        if(it->second->isRepeat())
        {
            it->second->moveToNext();
            insert(it->second);
        }
    }

    Timestamp nextExpire;
    if(!_timers.empty())
    {
        nextExpire = _timers.begin()->second->getStamp();
    }
    if(nextExpire.valid())
    {
        resetTimerfd(_timerfd, nextExpire);
    }
}

void TimerQueue::resetTimerfd(int timerfd, Timestamp stamp)
{
    struct itimerspec newValue;
    struct itimerspec oldValue;
    bzero(&newValue, sizeof(newValue));
    bzero(&oldValue, sizeof(oldValue));
    newValue.it_value = howMuchTimeFromNow(stamp);
    int ret = ::timerfd_settime(timerfd, 0, &newValue, &oldValue);
    if(ret)
    {
        std::cout << "timerfd_settime error\n";
    }
}

/*
 * set is used to store many timestamp->Timer which are unexpired
 * */
bool TimerQueue::insert(Timer* pTimer)
{
    bool earliestChanged = false;
    Timestamp when = pTimer->getStamp();
    TimerList::iterator it = _timers.begin();
    if(it == _timers.end() || when < it->first)
    {
        earliestChanged = true;
    }
    std::pair<TimerList::iterator, bool> result
            = _timers.insert(Entry(when, pTimer));
    if(!(result.second))
    {
        std::cout << "_timers.insert() error \n";
    }

    return earliestChanged;
}

struct timespec TimerQueue::howMuchTimeFromNow(Timestamp when)
{
    int64_t microseconds = when.microSecondsSinceEpoch()
                           - Timestamp::now().microSecondsSinceEpoch();
    if (microseconds < 100)
    {
        microseconds = 100;
    }
    struct timespec ts;
    ts.tv_sec = static_cast<time_t>(
            microseconds / Timestamp::kMicroSecondsPerSecond);
    ts.tv_nsec = static_cast<long>(
            (microseconds % Timestamp::kMicroSecondsPerSecond) * 1000);
    return ts;
}
