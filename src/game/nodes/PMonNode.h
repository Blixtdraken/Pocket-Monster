#pragma once
#include "../pmonster/PMon.h"
#include "interfaces/iNode.h"

class PMonNode: public se::iNode
{
    
    PMon& m_node_pmon;
    Texture2D* m_currentSprite = nullptr;
public:
    float m_scale = 10.0f;
    PMonNode(PMon& _pmon): m_node_pmon(_pmon){} // Temp test on the current srpite part

    void _ready() override;
    void _render() override;
    void _update(double _deltaTime) override;
};
