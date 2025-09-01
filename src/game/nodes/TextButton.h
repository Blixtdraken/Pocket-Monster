#pragma once
#include "Button.h"

class TextButton: public Button
{
    
public:
    std::string m_text;
    void _render() override;
    
};
