#pragma once
#include "../pmonster/PMon.h"
#include "interfaces/iNode.h"

class PMonNode: public se::iNode
{
    
    PMon* m_node_pmon;
    PMonNode* m_enemy_node;
    Texture2D* m_currentSprite = nullptr;
public:
    float m_scale = 10.0f;
    PMonNode(PMon* _pmon): m_node_pmon(_pmon){} // Temp test on the current srpite part

    void setEnemyPMon(PMonNode* _enemy){m_enemy_node = _enemy;}

    PMon* getPMon(){return m_node_pmon;}
    void setPMon(PMon* _pmon){m_node_pmon = _pmon;}
    
    void _ready() override;
    void _render() override;
    void _update(double _deltaTime) override;
};
