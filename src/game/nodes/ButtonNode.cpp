#include "ButtonNode.h"

#include <iostream>

void ButtonNode::_ready()
{
    iNode::_ready();
}

void ButtonNode::_handleInput()
{
    se::Vec2 mouse_pos = GetMousePosition();
    std::cout << "X: " << mouse_pos.x << "\n";
    std::cout << "Y: " << mouse_pos.y << "\n";
}

void ButtonNode::_update(double _deltaTime)
{
    iNode::_update(_deltaTime);
}

void ButtonNode::_render()
{
    iNode::_render();
}
