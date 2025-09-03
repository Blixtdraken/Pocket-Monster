#include "BackgroundNode.h"

void BackgroundNode::_ready()
{
    m_texture = LoadTexture("assets/sprites/background.png");
}

void BackgroundNode::_render()
{
    DrawTextureEx(m_texture, (m_position).rayify(), m_rotation, 10.0f, WHITE);
}

