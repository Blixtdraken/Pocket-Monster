#include <iostream>
#include "PMonNode.h"
#include "math/rgb.h"
#include "../consts.h"

void PMonNode::_ready()
{
    m_position = m_node_pmon->getSide() == MonsterSide::FRIEND ? FRIEND_MON_POS : ENEMEY_MON_POS ;
    
    m_currentSprite = m_node_pmon->getSprites()[ m_node_pmon->getSide() == MonsterSide::FRIEND ? 1 : 0 ];
}

void PMonNode::_render()
{
    float shadowScale = (m_scale*m_currentSprite->width)*0.66f;
    DrawEllipse(
        m_position.x, m_position.y, // Position
        shadowScale, shadowScale*0.33f, // Scale
        se::RGB(10, 10, 10, 80).rayify()); // Color

    se::Vec2 offset = se::Vec2(
    static_cast<float>(m_currentSprite->width)*0.5f*m_scale, // X
    static_cast<float>(m_currentSprite->height)*0.95f*m_scale // Y
    );
    DrawTextureEx(*m_currentSprite, (m_position-offset).rayify(), m_rotation, m_scale, WHITE);
    
    
   
}

void PMonNode::_update(double _deltaTime)
{
    
}
