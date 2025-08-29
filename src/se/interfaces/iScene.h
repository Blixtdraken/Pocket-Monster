#pragma once
#include <vector>

#include "iNode.h"
#include "../math/rgb.h"

namespace se
{
    class iScene
    {
    
        std::vector<iNode*> m_scene_nodes;
        
        
    public:
        RGB m_scene_color = GRAY;
        virtual void _sceneSetup()=0;
        

        void addNode(iNode* node);

        void nodesReady();
        
        void nodesHandleInput();
        void nodesUpdate(double _deltaTime);
        void nodesRender();

    
    };  
}
