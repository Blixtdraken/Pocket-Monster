#include "SceneMain.h"

#include "../pmonster/PMonNode.h"
#include "../pmonster/children/Gumboo.h"
#include "math/rgb.h"

void SceneMain::_sceneSetup()
{
    addNode(new PMonNode(*new Gumboo()));
    
    
    m_scene_color = RGB(189, 250, 255);
}
