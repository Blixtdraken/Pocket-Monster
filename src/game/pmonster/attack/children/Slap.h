#pragma once
#include "BasicAttack.h"

class Slap: public BasicAttack
{
protected:
    float getDamage() override{return 25.0f;}

public:
    const std::string getName() override;
    const std::string getDescription() override;
};
