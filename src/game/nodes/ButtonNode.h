#pragma once
#include <string>

#include "interfaces/iNode.h"

class ButtonNode: se::iNode
{
public:
    std::string m_title;
    std::string m_subtext;
        
    void _ready() override;
    void _handleInput() override;
    void _update(double _deltaTime) override;
    void _render() override;
};
