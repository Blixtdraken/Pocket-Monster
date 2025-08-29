#pragma once
#include "../math/vector2.h"

namespace se
{
    class iNode
    {
    public:
        Vec2 local_position;

        virtual void _ready(){}
        virtual void _handleInput(){}
        virtual void _update(double _deltaTime){}
        virtual void _render(){}
    };

}
