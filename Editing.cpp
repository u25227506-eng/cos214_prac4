#include "Editing.h"

Editing::Editing(const std::string& name, double budget, double time)
    : ConcreteTask(name, budget, time) {
}

Editing::~Editing() {
}