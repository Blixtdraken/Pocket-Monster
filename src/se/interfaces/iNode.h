#pragma once
#include "../math/vector2.h"


namespace se
{
    class iNode
    {
    public:
        bool visible = true;
        Vec2 m_position = Vec2(0.0f,0.0f);
        float m_rotation = 0.0f;
        virtual void _ready(){}
        virtual void _handleInput(){}
        virtual void _update(double _deltaTime){/*m_rotation += _deltaTime*1.0f; m_position = m_position.rotated_pivot(_deltaTime*200.0f, se::Vec2(GetScreenWidth()/2,GetScreenHeight()/2));*/}
        virtual void _render(){}
    };

}
