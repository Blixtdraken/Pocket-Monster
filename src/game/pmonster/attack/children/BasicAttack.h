#pragma once
#include "../Attack.h"
class BasicAttack: public Attack
{
public:
    void useAttack(PMon& _defending, PMon& _attacking) override;
    
protected:
    virtual float getDamage() = 0;

public:
    virtual const std::string& getName() = 0;
    virtual const std::string& getDescription() = 0;
};
