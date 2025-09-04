#include "HealingLeaf.h"

#include "../../iPMon.h"

void HealingLeaf::useAttack(iPMon&, iPMon& _attacking)
{
    _attacking.heal(30.0f);
}

const std::string HealingLeaf::getName()
{
    return "Healing Leaf";
}

const std::string HealingLeaf::getDescription()
{
    return "Heals you by 30 hitpoints!";
}
