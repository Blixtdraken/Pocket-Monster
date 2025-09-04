#pragma once
#include "../iAttack.h"

class HealingLeaf: public iAttack
{
public:
    void useAttack(iPMon& _defending, iPMon& _attacking) override;
    const std::string getName() override;
    const std::string getDescription() override;
};
