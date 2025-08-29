#pragma once
#include <vector>

#include "iNode.h"

namespace se
{
    class iScene
    {
    
        std::vector<iNode*> scene_nodes;
    public:
        iScene() {}
        virtual void _sceneSetup()=0;
    
    
        void nodesHandleInput();
        void nodesUpdate(double _deltaTime);
        void nodesRender();

    
    };  
}
