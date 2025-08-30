#include "SceneMain.h"


#include "../nodes/PMonNode.h"
#include "../pmonster/children/Gumboo.h"
#include "math/rgb.h"

void SceneMain::_sceneSetup()
{
    PMonNode* friend_pmon = new PMonNode(new Gumboo(MonsterSide::FRIEND));
    PMonNode* enemy_pmon = new PMonNode(new Gumboo(MonsterSide::ENEMY));
    friend_pmon->setEnemyPMon(enemy_pmon);
    enemy_pmon->setEnemyPMon(friend_pmon);
    addNode(friend_pmon);
    addNode(enemy_pmon);
    //SetWindowOpacity(0.1);
    //SetConfigFlags(FLAG_WINDOW_TRANSPARENT);
    
    m_scene_color = RGB(189, 250, 255, 0);
}
