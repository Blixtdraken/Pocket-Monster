#include "WindowManager.h"

void se::WindowManager::InitWindow(const Vec2I& _window_size)
{
    InitWindow(_window_size, GetMonitorRefreshRate(GetCurrentMonitor()));
}

void se::WindowManager::InitWindow(const Vec2I& _window_size, const int& _target_fps)
{
    ::InitWindow(_window_size.x, _window_size.y, "Sting Engine");
    SetTargetFPS(_target_fps);
}

void se::WindowManager::setTitle(const std::string& _title)
{
    ::SetWindowTitle(&_title[0]);
}
