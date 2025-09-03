#pragma once
#include "../iPMon.h"
#include "../attack/children/Goop.h"
#include "../PMonEnums.h"
class Gumboo: public iPMon
{
public:
    Gumboo(){}
    cElement test;
    std::vector<iAttack*>    getAttacks()    override;
    std::vector<Texture2D> getSprites()    override;
    std::vector<Element>    getElements()   override    { return { NORMAL, WATER };}

    float getMaxHP() override{return 280.0f;}
    const std::string getName() override;
};
