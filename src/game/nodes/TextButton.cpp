#include "TextButton.h"

void TextButton::_render()
{
    Button::_render();
    Font font = Font();
    
    DrawTextEx(font, &m_text[0], (m_position+se::Vec2(border_width)).rayify(), m_size.y*0.25, 2.0f, BLACK);
}
