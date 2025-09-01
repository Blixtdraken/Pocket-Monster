#pragma once
#include "../iAttack.h"
class BasicAttack: public iAttack
{
public:
    void useAttack(iPMon& _defending, iPMon& _attacking) override;
    
protected:
    virtual float getDamage() = 0;

public:
    virtual const std::string getName() = 0;
    virtual const std::string getDescription() = 0;
    const int getCooldown() override{return 0.0f;}
};
