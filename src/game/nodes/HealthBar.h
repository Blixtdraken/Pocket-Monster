#pragma once
#include "../pmonster/iPMon.h"
#include "interfaces/iNode.h"

class HealthBar: public se::iNode
{
public:
    HealthBar(iPMon* _pmon):m_pmon(_pmon){}

    se::Vec2 m_size = {450, 80};
    
    void _render() override;
private:
    iPMon* m_pmon = nullptr;

};
