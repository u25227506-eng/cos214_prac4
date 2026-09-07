#include "Recording.h"

Recording::Recording(const std::string& name, double budget, double time)
    : ConcreteTask(name, budget, time) {
}

Recording::~Recording() {
}