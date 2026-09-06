#ifndef FINISHEDSTATE_H
#define FINISHEDSTATE_H

#include "TaskState.h"

class FinishedState : public TaskState {
    public: 
        void start(ConcreteTask* task) override;
        void finish(ConcreteTask* task) override;
        void delay(ConcreteTask* task) override;
        std::string getStateName() const override;
};

#endif //FINISHEDSTATE_H