#pragma once
#include <string>

class PMon;

class Attack
{
public:
    virtual void useAttack(PMon& _defending, PMon& _attacking) = 0;
    virtual const std::string& getName() = 0;
    virtual const std::string& getDescription() = 0;
    //virtual void getSymbol(PMon& _defending, PMon& _attacking) = 0;
};
