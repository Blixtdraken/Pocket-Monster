#pragma once
#include <functional>
#include <string>

#include "interfaces/iNode.h"



class Button: public se::iNode
{
public:
    se::Vec2 m_size = {250, 80};
    float border_width = 6.0f;

    
    
    void _ready() override;
    void _handleInput() override;
    void _update(double _deltaTime) override;
    void _render() override;

    bool isPressed(){return m_is_pressed;}
    bool isJustPressed(){return m_is_just_pressed;}
    bool isJustReleased(){return m_is_just_released;}
    bool isHovered(){return m_is_hovered;}

    void setOnPressed(std::function<void()> _on_pressed){m_on_pressed = _on_pressed;}
    void setOnReleased(std::function<void()> _on_released){m_on_released = _on_released;}

    void activate(){active = true;}
    void deactivate(){active = false;}

    bool active = true;
protected:
    std::function<void()> m_on_pressed = nullptr;
    std::function<void()> m_on_released = nullptr;
    bool m_is_pressed = false;
    bool m_is_just_pressed = false;
    bool m_is_just_released = false;
    bool m_is_hovered = false;


};
