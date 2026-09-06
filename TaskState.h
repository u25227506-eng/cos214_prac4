#ifndef TASKSTATE_H
#define TASKSTATE_H

#include <string> 

class ConcreteTask;

class TaskState{
    public:     
        virtual ~TaskState();
        virtual void start(ConcreteTask* task) = 0;
        virtual void finish(ConcreteTask* task) = 0;
        virtual void delay(ConcreteTask* task) = 0;

        virtual std::string getStateName() const =0;

};

#endif //TASKSTATE_H