#pragma once
#include "interfaces/iNode.h"

class BackgroundNode : public se::iNode
{
protected:
    Texture2D m_texture;
public:
    void _ready() override;
    
    void _render() override;

    
};
