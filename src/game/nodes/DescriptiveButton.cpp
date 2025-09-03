#include "DescriptiveButton.h"

void DescriptiveButton::_render()
{
    Button::_render();
    Font font = Font();
    
    DrawTextEx(font, m_title.c_str(), (m_position+se::Vec2(border_width)).rayify(), m_size.y*0.25, 2.0f, BLACK);
    
    
    std::string str_buffer;
    std::vector<std::string> str_vector;
    
    char delimiter = '\n';
    str_vector.reserve(m_desc.find(delimiter) + 1);
    for (char c : m_desc)
    {
        if (c == delimiter)
        {
            str_vector.push_back(str_buffer);
            str_buffer.clear();
        }
        else
        {
            str_buffer.push_back(c);
        }
    }
    if (!str_buffer.empty()) str_vector.push_back(str_buffer);

    for (int i = 0; i < str_vector.size(); i++)
    {
        se::Vec2 pos = m_position+se::Vec2(border_width)+se::Vec2(0, (m_size.y*0.25));
        pos += se::Vec2(0, (m_size.y*0.125f*i));
        DrawTextEx(font, str_vector[i].c_str(), pos.rayify(), m_size.y*0.125, 2.0f, BLACK);
    }
    
}
