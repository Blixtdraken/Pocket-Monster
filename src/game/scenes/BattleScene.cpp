#include "BattleScene.h"

#include <iostream>
#include <print>


#include "../BattleManager.h"
#include "../nodes/DescriptiveButton.h"
#include "../nodes/HealthBar.h"
#include "../nodes/PMonNode.h"
#include "../pmonster/children/Gumboo.h"
#include "../nodes/BackgroundNode.h"
#include "math/rgb.h"

void BattleScene::_sceneSetup()
{
    addNode(new BackgroundNode());
    
    m_scene_color = se::RGB(189, 250, 255, 0);

    addNode(new BattleManager(*this));


    
    
    
    
    
    
}
