#pragma once
#include "../iPMon.h"

class Branchey: public iPMon
{
public:
    cElement test;
    std::vector<iAttack*>    getAttacks()    override;
    std::vector<Texture2D>   getSprites()    override;
    std::vector<Element>     getElements()   override    { return { GRASS };}

    float getMaxHP() override{return 180.0f;}
    const std::string getName() override;
};
