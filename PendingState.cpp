#include "PendingState.h"
#include "InProgressState.h"
#include "ConcreteTask.h"
#include <iostream>

void PendingState::start(ConcreteTask* task){
    task->setState(new InProgressState());
}

void PendingState::finish(ConcreteTask* task) {
    std::cout << "Cannot finish \"" << task->getName() << "\" - it hasn't been started yet" << std::endl;
}

void PendingState::delay(ConcreteTask* task){
    std::cout << "Cannot delay \"" << task->getName() << "\" - it hasn't been started yet" << std::endl;
}

std::string PendingState::getStateName() const{
    return "Pending";
}