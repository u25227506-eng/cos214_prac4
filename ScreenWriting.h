#pragma once

#include "ConcreteTask.h"

class ScreenWriting : public ConcreteTask {
public:
    ScreenWriting(const std::string& name, double budget, double time);
    ~ScreenWriting();
};

