#include "InProgressState.h"
#include "FinishedState.h"
#include "DelayedState.h"
#include "ConcreteTask.h"

#include <iostream>

void InProgressState::start(ConcreteTask* task) {
    std::cout << "\"" << task->getName() << "\" is already in progress" << std::endl;
}

void InProgressState::finish(ConcreteTask* task){
    task->setState(new FinishedState());
}

void InProgressState::delay(ConcreteTask* task){
    task->setState(new DelayedState());
}

std::string InProgressState::getStateName() const {
    return "In Progress";
}