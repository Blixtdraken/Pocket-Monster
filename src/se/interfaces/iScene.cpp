#include "iScene.h"

void se::iScene::addNode(iNode* node)
{
    m_scene_nodes.push_back(node);
}

void se::iScene::nodesReady()
{
    for (auto node : m_scene_nodes)
    {
        node->_ready();
    }
}

void se::iScene::nodesHandleInput()
{
    for (auto node : m_scene_nodes)
    {
        node->_handleInput();
    }
}

void se::iScene::nodesUpdate(double _deltaTime)
{
    for (auto node : m_scene_nodes)
    {
        node->_update(_deltaTime);
    }
}

void se::iScene::nodesRender()
{
    for (auto node : m_scene_nodes)
    {
        if (!node->visible) continue;
        node->_render();
        
    }
}
