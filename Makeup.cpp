#include "Makeup.h"

Makeup::Makeup(const std::string& name, double budget, double time)
    : ConcreteTask(name, budget, time) {
}

Makeup::~Makeup() {
}