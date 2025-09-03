#include "Gumboo.h"


std::vector<iAttack*> Gumboo::getAttacks()
{
    return {
        new Goop()
    }; 
}

std::vector<Texture2D> Gumboo::getSprites()
{
    return
    {
    LoadTexture("assets/sprites/gumboo-1.png"),
    LoadTexture("assets/sprites/gumboo-2.png"),
    };
    
}

const std::string Gumboo::getName()
{
    return "Gumboo";
}
