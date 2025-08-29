#pragma once
#include "../PMon.h"
#include "../attack/children/Goop.h"

class Gumboo: public PMon
{
public:
    Gumboo(MonsterSide _side): PMon(80.0f, _side){}
    
    std::vector<Attack*>    getAttacks()    override
    {
        return {
            new Goop()
        };
    }
    std::vector<Texture2D*> getSprites()    override;
    std::vector<Element>    getElements()   override{return {};}
};
