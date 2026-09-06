#include "TaskDecorator.h"

TaskDecorator::TaskDecorator(FilmProductionComp* comp) : FilmProductionComp(comp->getName()), wrapped(comp){}

std::string TaskDecorator::getName() const {
    return wrapped->getName();
}

void TaskDecorator::start(){
    wrapped->start();
}

void TaskDecorator::finish(){
    wrapped->finish();
}

void TaskDecorator::delay(){
    wrapped->delay();
}

std::string TaskDecorator::getStateName() const {
    return wrapped->getStateName();
}

TaskDecorator::~TaskDecorator(){
    delete wrapped;
}