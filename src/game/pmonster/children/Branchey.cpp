#include "Branchey.h"

#include "../attack/children/HealingLeaf.h"
#include "../attack/children/Slap.h"

std::vector<iAttack*> Branchey::getAttacks()
{
    return {
        new Slap(),
        new HealingLeaf()
    };
}

std::vector<Texture2D> Branchey::getSprites()
{
    return
{
    LoadTexture("assets/sprites/branchey-1.png"),
    LoadTexture("assets/sprites/branchey-2.png"),
    };
}

const std::string Branchey::getName()
{
    return "Branchey";
}
