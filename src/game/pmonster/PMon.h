#pragma once
#include <vector>

#include "attacks/Attack.h"


enum class Element
{
    //Just to check comitts ???
};

class PMon
{
private:
    float m_hp;

public:
    virtual float getMaxHP() = 0;
    virtual std::vector<Attack>  getAttacks() = 0;
protected:
    
};
