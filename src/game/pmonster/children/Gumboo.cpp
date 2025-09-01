#include "Gumboo.h"


std::vector<iAttack*> Gumboo::getAttacks()
{
    return {
        new Goop()
    }; 
}

std::vector<Texture2D*> Gumboo::getSprites()
{
    return
    {
    new Texture2D(LoadTexture("assets/sprites/gumboo-1.png")),
    new Texture2D(LoadTexture("assets/sprites/gumboo-2.png")),
    };
    
}
