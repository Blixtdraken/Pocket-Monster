#include "BattleScene.h"

#include <print>


#include "../nodes/TextButton.h"
#include "../nodes/PMonNode.h"
#include "../pmonster/children/Gumboo.h"
#include "math/rgb.h"

void BattleScene::_sceneSetup()
{
    m_scene_color = se::RGB(189, 250, 255, 0);
    ///////////////////////////////////////////////////////////////////////////////
    PMonNode* friend_pmon = new PMonNode(new Gumboo(MonsterSide::FRIEND));
    PMonNode* enemy_pmon = new PMonNode(new Gumboo(MonsterSide::ENEMY));
    friend_pmon->setEnemyPMon(enemy_pmon);
    enemy_pmon->setEnemyPMon(friend_pmon);
    addNode(friend_pmon);
    addNode(enemy_pmon);
    ///////////////////////////////////////////////////////////////////////////////
    std::vector<TextButton*> attack_buttons = {};
    attack_buttons.resize(4);
     std::vector<iAttack*> friend_attacks = friend_pmon->getPMon()->getAttacks();
    for (int i = 0; i < attack_buttons.size(); i++)
    {
        attack_buttons[i] = new TextButton();
        if (i < friend_attacks.size())
        {
            iAttack* attack = friend_attacks[i];
            attack_buttons[0]->setOnReleased([=]
            {
                std::printf("%s\n", attack->getName().c_str()); //TODO
            });
        }

        addNode(attack_buttons[i]);
    }

    
    
  
    
    attack_buttons[0]->m_position = {
        SCREEN_WIDTH-attack_buttons[0]->m_size.x*2.0f,
        SCREEN_HEIGHT-attack_buttons[0]->m_size.y*2.0f
    };
    attack_buttons[1]->m_position = {
        SCREEN_WIDTH-attack_buttons[1]->m_size.x,
        SCREEN_HEIGHT-attack_buttons[1]->m_size.y*2.0f
    };
    attack_buttons[2]->m_position = {
        SCREEN_WIDTH-attack_buttons[2]->m_size.x*2.0f,
        SCREEN_HEIGHT-attack_buttons[2]->m_size.y
    };
    attack_buttons[3]->m_position = {
        SCREEN_WIDTH-attack_buttons[3]->m_size.x,
        SCREEN_HEIGHT-attack_buttons[3]->m_size.y
    };
    addNode(new Button());
    
    
    
    
    
}
