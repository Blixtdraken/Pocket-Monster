#pragma once
#include "src/math/vector2.h"

namespace se
{
    class RayWindowManager
    {
    public:
        void InitWindow(Vec2I _window_size);
        void InitWindow(Vec2I _window_size, int _target_fps);
    };
}

