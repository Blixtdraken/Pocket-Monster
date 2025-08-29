#pragma once
#include "../PMon.h"
class Gumboo: public PMon
{
public:

    float getMaxHP() override{return 80.0f;}
    std::vector<Attack> getAttacks() override;
    
};
