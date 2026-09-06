#include "ConcreteTask.h"
#include "TaskState.h"
#include "PendingState.h"

ConcreteTask::ConcreteTask(const std::string& name, double budget, double time) : FilmProductionComp(name), budget(budget), time(time), state(new PendingState()) {}

ConcreteTask::~ConcreteTask(){
    delete state;
}

double ConcreteTask::getBudget() const {
    return budget;
}

double ConcreteTask::getTime() const{
    return time;
}

void ConcreteTask::start(){
    state->start(this);
}

void ConcreteTask::finish(){
    state->finish(this);
}

void ConcreteTask::delay(){
    state->delay(this);
}

void ConcreteTask::setState(TaskState* newState){
    delete state;
    state = newState;
}

std::string ConcreteTask::getStateName() const {
    return state->getStateName();
}