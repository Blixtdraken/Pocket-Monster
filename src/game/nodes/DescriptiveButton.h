#pragma once
#include "Button.h"

class DescriptiveButton: public Button
{
    
public:
    std::string m_title;
    std::string m_desc;
    void _render() override;
    
};
