#include "BattleManager.h"

#include "nodes/HealthBar.h"
#include "pmonster/children/Gumboo.h"


BattleManager::BattleManager(se::iScene& scene)
{

    m_player = new PMonNode({
        new Gumboo()
    }, MonsterSide::FRIEND);
    
    m_enemy = new PMonNode({
        new Gumboo()
    }, MonsterSide::ENEMY);

    scene.addNode(m_player);
    scene.addNode(m_enemy);

    
    ///////////////////////////////////////////////////////////////////////////////
    HealthBar* health_bar_friend = new HealthBar(m_player->getPMon());
    HealthBar* health_bar_enemy = new HealthBar(m_enemy->getPMon());
    health_bar_enemy->m_position.x = SCREEN_WIDTH-health_bar_enemy->m_size.x;
    scene.addNode(health_bar_friend);
    scene.addNode(health_bar_enemy);
    ///////////////////////////////////////////////////////////////////////////////

    
    
    m_attack_buttons.resize(4);
    std::vector<iAttack*> friend_attacks = m_player->getPMon()->getAttacks();
    for (int i = 0; i < m_attack_buttons.size(); i++)
    {
        m_attack_buttons[i] = new DescriptiveButton();
        if (i < friend_attacks.size())
        {
            iAttack* attack = friend_attacks[i];
            m_attack_buttons[i]->setOnReleased([=]
            {
                attack->useAttack(*m_enemy->getPMon(), *m_player->getPMon());
                setAttackButtonsVisible(false);
                this->m_turnstate = ENEMY_TURN;
                this->startTimer();
            });
            m_attack_buttons[i]->m_title = attack->getName();
            m_attack_buttons[i]->m_desc = attack->getDescription();
        }else
        {
            m_attack_buttons[i]->deactivate();
        }

        scene.addNode(m_attack_buttons[i]);
    }

    
    
  
    
    m_attack_buttons[0]->m_position = {
        SCREEN_WIDTH-m_attack_buttons[0]->m_size.x*2.0f,
        SCREEN_HEIGHT-m_attack_buttons[0]->m_size.y*2.0f
    };
    m_attack_buttons[1]->m_position = {
        SCREEN_WIDTH-m_attack_buttons[1]->m_size.x,
        SCREEN_HEIGHT-m_attack_buttons[1]->m_size.y*2.0f
    };
    m_attack_buttons[2]->m_position = {
        SCREEN_WIDTH-m_attack_buttons[2]->m_size.x*2.0f,
        SCREEN_HEIGHT-m_attack_buttons[2]->m_size.y
    };
    m_attack_buttons[3]->m_position = {
        SCREEN_WIDTH-m_attack_buttons[3]->m_size.x,
        SCREEN_HEIGHT-m_attack_buttons[3]->m_size.y
    };
}



void BattleManager::_ready()
{
    iNode::_ready();
}

void BattleManager::_handleInput()
{
    iNode::_handleInput();
}

void BattleManager::startTimer()
{
    m_timer = 0.0f;
    m_animating = true;
}

void BattleManager::openSelector()
{
    
}

void BattleManager::_update(double _deltaTime)
{
    
    
    if (m_animating)
    {
        m_timer += _deltaTime;
        if (m_timer > ANIMATION_TIME) m_animating = false;
        else return;
    }
    
    if (m_is_selecting) return;

    handleDeadEnemy();
    handleDeadPlayer();
    
    switch(m_turnstate)
    {
    case PLAYER_TURN:
        handlePlayerTurn();
       break;
    case ENEMY_TURN:
        handleEnemyTurn();
        break;
    }
}

void BattleManager::handleDeadPlayer()
{
    //TODO: Chekc player health and enemey health and then trigger m_selecing = true thingies
}
void BattleManager::handleDeadEnemy()
{
    
}


void BattleManager::handlePlayerTurn()
{
    setAttackButtonsVisible(true);
}


void BattleManager::handleEnemyTurn()
{
    std::vector<iAttack*> enemy_attacks = m_enemy->getPMon()->getAttacks();
    iAttack* selected_attack = enemy_attacks[GetRandomValue(0, enemy_attacks.size()-1)];
    selected_attack->useAttack(*m_player->getPMon(), *m_enemy->getPMon());
    m_turnstate = PLAYER_TURN;
    startTimer();
}

void BattleManager::setAttackButtonsVisible(bool _visible)
{
    for (DescriptiveButton* button : m_attack_buttons)
    {
        button->visible = _visible;
    }
}
void BattleManager::setSelectButtonsVisible(bool _visible)
{
    for (TextButton* button : m_pmon_buttons)
    {
        button->visible = _visible;
    }
}


void BattleManager::_render()
{
    iNode::_render();
}
