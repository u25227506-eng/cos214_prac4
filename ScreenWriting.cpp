#include "ScreenWriting.h"

ScreenWriting::ScreenWriting(const std::string& name, double budget, double time)
    : ConcreteTask(name, budget, time) {
}

ScreenWriting::~ScreenWriting() {
}