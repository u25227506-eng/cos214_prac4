#include "DelayedState.h"
#include "InProgressState.h"
#include "ConcreteTask.h"
#include <iostream>

void DelayedState::start(ConcreteTask* task){
    //resuming a delayed task to put it in progress
    task->setState(new InProgressState());
}

void DelayedState::finish(ConcreteTask* task){
    std::cout << "Cannot finish \"" << task->getName() << "\" - it is delayed. Resume it first." << std::endl;
}

void DelayedState::delay(ConcreteTask* task){
    std::cout << "\"" << task->getName() << "\" - is already delayed" << std::endl;
}

std::string DelayedState::getStateName() const {
    return "Delayed";
}