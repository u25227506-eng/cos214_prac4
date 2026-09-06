#ifndef INPROGRESSSTATE_H
#define INPROGRESSSTATE_H

#include "TaskState.h"

class InProgressState : public TaskState {
    public:
        void start(ConcreteTask* task) override;
        void finish(ConcreteTask* task) override;
        void delay(ConcreteTask* task) override;
        std::string getStateName() const override;
};

#endif //INPROGRESSSTATE_H