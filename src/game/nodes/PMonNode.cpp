#include <iostream>
#include "PMonNode.h"
#include "math/rgb.h"
#include "../consts.h"

void PMonNode::setPMonIndex(const int& _index)
{
    if (getPMonIndex() == _index) return;
    
    m_current_pokemon = _index;
    updateSprite();
    m_on_pmon_changed(m_pmons[m_current_pokemon]);
    
}

void PMonNode::updateSprite()
{
    UnloadTexture(m_currentSprite);
    m_currentSprite = m_pmons[m_current_pokemon]->getSprites()[m_side == MonsterSide::FRIEND ? 1 : 0 ];
}

void PMonNode::_ready()
{
    m_position = m_side == MonsterSide::FRIEND ? FRIEND_MON_POS : ENEMEY_MON_POS ;
    
    updateSprite();
}

void PMonNode::_render()
{
    float shadowScale = (m_scale*m_currentSprite.width)*0.66f;
    shadowScale = 0;
    DrawEllipse(
        m_position.x, m_position.y, // Position
        shadowScale, shadowScale*0.33f, // Scale
        se::RGB(10, 10, 10, 80).rayify()); // Color

    se::Vec2 offset = se::Vec2(
    static_cast<float>(m_currentSprite.width)*0.5f*m_scale, // X
    static_cast<float>(m_currentSprite.height)*0.95f*m_scale // Y
    );
    DrawTextureEx(m_currentSprite, (m_position-offset).rayify(), m_rotation, m_scale, WHITE);
    

}

void PMonNode::_update(double _deltaTime)
{
    
}
