#pragma once
#include "../pmonster/iPMon.h"
#include "interfaces/iNode.h"

class PMonNode: public se::iNode
{
    int m_current_pokemon = 0;
    std::vector<iPMon*> m_pmons;

    MonsterSide m_side;
    
    Texture2D m_currentSprite;
public:
    float m_scale = 10.0f;
    PMonNode(std::vector<iPMon*> _pmons, MonsterSide _side): m_pmons(_pmons), m_side(_side){} // Temp test on the current srpite part

    
    MonsterSide getSide(){return m_side;}
    iPMon* getPMon(){return m_pmons[m_current_pokemon];}
    void setPMonIndex(const int& _index){m_current_pokemon = _index;}

    void updateSprite();
    
    void _ready() override;
    void _render() override;
    void _update(double _deltaTime) override;
};
