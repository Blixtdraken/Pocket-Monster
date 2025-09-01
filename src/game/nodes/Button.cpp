#include "Button.h"

#include <iostream>

#include "math/rgb.h"

void Button::_ready()
{
    iNode::_ready();
}

void Button::_handleInput()
{
    se::Vec2 mouse_pos = GetMousePosition();
    //std::cout << "X: " << mouse_pos.x << " | Y: " << mouse_pos.y << "\n";

    se::Vec2 rect_min = m_position;
    se::Vec2 rect_max = m_position + m_size;

    if (
        rect_min.x < mouse_pos.x &&
        rect_min.y < mouse_pos.y &&
        rect_max.x > mouse_pos.x &&
        rect_max.y > mouse_pos.y
        )
    {
        m_is_hovered = true;
        
        if ((m_is_just_pressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
        {
            m_is_pressed = true;
        }
        else if ((m_is_just_released = IsMouseButtonReleased(MOUSE_BUTTON_LEFT)))
        {
            m_is_pressed = false;
        }

       
        
    }
    else
    {
        if (m_is_pressed && (m_is_just_released = IsMouseButtonReleased(MOUSE_BUTTON_LEFT)))
        {
            m_is_pressed = false;
        }
        m_is_hovered = false;
    }
}

void Button::_update(double _deltaTime)
{
    if (m_on_pressed && isJustPressed()) m_on_pressed();
    
    if (m_on_released && isJustReleased()) m_on_released();
    
}

void Button::_render()
{
    
    
    se::RGB color = isHovered() ? LIGHTGRAY : WHITE;
    color = isPressed() ? GRAY : color;
    se::RGB acc_color = isPressed() ? ORANGE : SKYBLUE;
    
    Rectangle rect = Rectangle();
    Rectangle inner_rect = Rectangle();
    
    

    rect.width = abs(m_size.x);
    rect.height = abs(m_size.y);
    
    inner_rect.width = abs(m_size.x)-border_width;
    inner_rect.height = abs(m_size.y)-border_width;
    
    
    
    DrawRectanglePro(rect, m_position.invert().rayify(), 0.0f, acc_color.rayify());
    DrawRectanglePro(inner_rect, (m_position.invert()-se::Vec2(border_width/2.0f)).rayify(), 0.0f, color.rayify());
    
   
    
}
