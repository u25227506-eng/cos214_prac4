#include "FinishedState.h"
#include "ConcreteTask.h"
#include <iostream>

void FinishedState::start(ConcreteTask* task){
    std::cout << "\"" << task->getName() << "\" is already finished" << std::endl;
}

void FinishedState::finish(ConcreteTask* task){
    std::cout << "\"" << task->getName() << "\" is already finished" << std::endl;
}

void FinishedState::delay(ConcreteTask* task){
    std::cout << "Cannot delay \"" << task->getName() << "\" - it is already finished" << std::endl;
}

std::string FinishedState::getStateName() const {
    return "Finished";
}