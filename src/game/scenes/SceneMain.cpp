#include "SceneMain.h"


#include "../nodes/PMonNode.h"
#include "../pmonster/children/Gumboo.h"
#include "math/rgb.h"

void SceneMain::_sceneSetup()
{
    addNode(new PMonNode(*new Gumboo(MonsterSide::FRIEND)));
    addNode(new PMonNode(*new Gumboo(MonsterSide::ENEMY)));
    //SetWindowOpacity(0.1);
    //SetConfigFlags(FLAG_WINDOW_TRANSPARENT);
    
    m_scene_color = RGB(189, 250, 255, 0);
}
