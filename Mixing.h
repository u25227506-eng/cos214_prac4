#pragma once

#include "ConcreteTask.h"

class Mixing : public ConcreteTask {
public:
    Mixing(const std::string& name, double budget, double time);
    ~Mixing();
};

