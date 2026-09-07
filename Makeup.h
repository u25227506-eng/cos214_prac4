#pragma once

#include "ConcreteTask.h"

class Makeup : public ConcreteTask {
public:
    Makeup(const std::string& name, double budget, double time);
    ~Makeup();
};

