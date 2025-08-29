#pragma once
#include "PMon.h"
#include "interfaces/iNode.h"

class PMonNode: public se::iNode
{
    
    PMon& m_node_pmon;
    Texture2D* m_currentSprite = nullptr;
public:
    PMonNode(PMon& _pmon): m_node_pmon(_pmon), m_currentSprite(_pmon.getSprites()[0]){} // Temp test on the current srpite part
    void _render() override;
};
