#include "TaskDecorator.h"
#include "PendingState.h"
#include <iostream>

TaskDecorator::TaskDecorator(FilmProductionComp* comp, double budget, double time)
    : FilmProductionComp(comp->getName()) {
    this->Comp = comp;
    this->extraBudget = budget;
    this->extraTime = time;
    this->taskState = new PendingState();
}

TaskDecorator::~TaskDecorator() {
    delete taskState;
    delete Comp;
}

TaskState* TaskDecorator::getState() {
    return taskState;
}

void TaskDecorator::setState(TaskState* taskState) {
    if (this->taskState != taskState) {
        delete this->taskState;
    }
    this->taskState = taskState;
}

void TaskDecorator::add(FilmProductionComp* comp) {
    std::cout << "Cannot add to a task decorator." << std::endl;
}

void TaskDecorator::remove(FilmProductionComp* comp) {
    std::cout << "Cannot remove from a task decorator." << std::endl;
}

FilmProductionComp* TaskDecorator::getChild(int index) {
    return nullptr;
}

double TaskDecorator::getBudget() const {
    return Comp->getBudget() + extraBudget;
}

double TaskDecorator::getTime() const {
    return Comp->getTime() + extraTime;
}

std::string TaskDecorator::getStateName() const {
    return Comp->getStateName();
}