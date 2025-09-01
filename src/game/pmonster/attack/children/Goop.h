#pragma once
#include "BasicAttack.h"
#include "../Attack.h"

class Goop: public BasicAttack
{
public:
    
    
protected:
    float getDamage() override{return 60.0f;}

public:
    const std::string& getName() override;
    const std::string& getDescription() override;
};
