#include "Mixing.h"

Mixing::Mixing(const std::string& name, double budget, double time)
    : ConcreteTask(name, budget, time) {
}

Mixing::~Mixing() {
}