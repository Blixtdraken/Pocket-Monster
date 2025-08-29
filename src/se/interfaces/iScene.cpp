#include "iScene.h"

void se::iScene::nodesHandleInput()
{
    for (auto node : scene_nodes)
    {
        node->_handleInput();
    }
}

void se::iScene::nodesUpdate(double _deltaTime)
{
    for (auto node : scene_nodes)
    {
        node->_update(_deltaTime);
    }
}

void se::iScene::nodesRender()
{
    BeginDrawing();
    for (auto node : scene_nodes)
    {
        node->_render();
    }
    EndDrawing();
}
