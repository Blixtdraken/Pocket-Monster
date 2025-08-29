#include "Gumboo.h"

std::vector<Attack*> Gumboo::getAttacks()
{
    std::vector<Attack*> attacks;
    
    return attacks;
}

std::vector<Texture2D*> Gumboo::getSprites()
{
    std::vector<Texture2D*> sprites;

    sprites.push_back(new Texture2D(LoadTexture("assets/sprites/gumboo-1.png")));
    sprites.push_back(new Texture2D(LoadTexture("assets/sprites/gumboo-2.png")));

    return sprites;
}
