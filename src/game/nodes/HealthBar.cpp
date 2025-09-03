#include "HealthBar.h"

#include <format>

#include "math/rgb.h"


void HealthBar::_render()
{
    float hp_ratio = m_pmon->getHP()/m_pmon->getMaxHP();
    
    std::string pmon_name = m_pmon->getName();
    float border_width = 6.0;
    Rectangle rect = Rectangle();
    rect.width = m_size.x;
    rect.height = m_size.y;
    DrawRectanglePro(rect, m_position.invert().rayify(), m_rotation, WHITE);
    rect.width -= border_width*2.0f;
    rect.height -= border_width*2.0f;
    rect.height /= 2.0f;
    DrawRectanglePro(rect, (m_position+se::Vec2(border_width)+se::Vec2(0, m_size.y/2.0f - border_width)).invert().rayify(), m_rotation, DARKBROWN);
    rect.width *= hp_ratio;
    DrawRectanglePro(rect, (m_position+se::Vec2(border_width)+se::Vec2(0, m_size.y/2.0f - border_width)).invert().rayify(), m_rotation, GREEN);
    Font font = GetFontDefault();
    float font_size = m_size.y/2.5f;
    float font_spacing = 10.0f;
    DrawTextEx(font,std::format("{}/{}", (int)m_pmon->getHP(),(int)m_pmon->getMaxHP()).c_str(), (m_position+(border_width)).rayify(), font_size, font_spacing, BLACK);
    Vector2 text_length = MeasureTextEx(font, pmon_name.c_str() , font_size, font_spacing);
    DrawTextEx(font,pmon_name.c_str(), (m_position+(border_width)+se::Vec2( m_size.x - text_length.x - border_width*2.0f, 0.0f)).rayify(), font_size, font_spacing, BLACK);
}
