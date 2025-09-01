#include "BasicAttack.h"

#include "../../iPMon.h"

void BasicAttack::useAttack(iPMon& _defending, iPMon&)
{
    _defending.damage(getDamage());
}
