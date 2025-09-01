#pragma once
#include "BasicAttack.h"
#include "../iAttack.h"

class Goop: public BasicAttack
{
private:
    
    
protected:
    float getDamage() override{return 60.0f;}

public:
    const std::string getName() override;
    const std::string getDescription() override;
};
