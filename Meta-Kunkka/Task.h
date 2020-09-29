#ifndef RANET_TASK_H
#define RANET_TASK_H
#include<string>
#include"Declare.h"

class Task
{
public:
    Task(IRun0* func);
    Task(IRun2* func, const std::string& str, void* param);
    void doTask();
private:
    IRun0* _func0;
    IRun2* _func2;
    std::string _str;
    void* _param;
};

#endif //RANET_TASK_H
