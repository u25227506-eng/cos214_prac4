#pragma once

#include "ConcreteTask.h"

class StoryBoarding : public ConcreteTask {
public:
    StoryBoarding(const std::string& name, double budget, double time);
    ~StoryBoarding();
};

