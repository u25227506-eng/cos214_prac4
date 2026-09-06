#ifndef PENDINGSTATE_H
#define PENDINGSTATE_H


#include "TaskState.h"

class PendingState : public TaskState {
    public: 
        void start(ConcreteTask* task) override;
        void finish(ConcreteTask* task) override;
        void delay(ConcreteTask* task) override;

        std::string getStateName() const override;
};

#endif //PENDINGSTATE_H