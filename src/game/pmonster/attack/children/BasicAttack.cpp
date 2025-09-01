#include "BasicAttack.h"

#include "../../PMon.h"

void BasicAttack::useAttack(PMon& _defending, PMon&)
{
    _defending.damage(getDamage());
}
