#include "StoryBoarding.h"

StoryBoarding::StoryBoarding(const std::string& name, double budget, double time)
    : ConcreteTask(name, budget, time) {
}

StoryBoarding::~StoryBoarding() {
}