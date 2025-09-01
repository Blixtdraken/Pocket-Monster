#pragma once
#include <string>

class iPMon;

class iAttack
{
public:
    virtual void useAttack(iPMon& _defending, iPMon& _attacking) = 0;
    virtual const std::string& getName() = 0;
    virtual const std::string& getDescription() = 0;
    virtual const int& getCooldown() = 0;
    //virtual void getSymbol(PMon& _defending, PMon& _attacking) = 0;
};
