#pragma once
#include <string>

#include "math/vector2.h"

namespace se
{
    class WindowManager
    {

    public://////////////////////////////////
        static WindowManager& GetInstance(){static WindowManager* m_instance = nullptr; if (m_instance) return *m_instance; m_instance = new WindowManager(); return *m_instance;}
    
    public:
        void InitWindow(const Vec2I& _window_size);
        void InitWindow(const Vec2I& _window_size, const int& _target_fps);
        void setTitle(const std::string& _title);
    };
}

