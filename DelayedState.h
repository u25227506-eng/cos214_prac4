#ifndef DELAYEDSTATE_H
#define DELAYEDSTATE_H

#include "TaskState.h"

class DelayedState : public TaskState {
    public:
        void start(ConcreteTask* task) override;
        void finish(ConcreteTask* task) override;
        void delay(ConcreteTask* task) override;
        std::string getStateName() const override;
};

#endif //DELAYEDSTATE_H