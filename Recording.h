#pragma once

#include "ConcreteTask.h"

class Recording : public ConcreteTask {
public:
    Recording(const std::string& name, double budget, double time);
    ~Recording();
};

