#include "BattleManager.h"

#include "nodes/HealthBar.h"
#include "pmonster/children/Branchey.h"
#include "pmonster/children/Gumboo.h"


BattleManager::BattleManager(se::iScene& _scene)
{

    m_player = new PMonNode({
        new Gumboo(),
        new Branchey(),
    }, MonsterSide::FRIEND);
    
    m_enemy = new PMonNode({
        new Gumboo()
    }, MonsterSide::ENEMY);

    _scene.addNode(m_player);
    _scene.addNode(m_enemy);

    
    ///////////////////////////////////////////////////////////////////////////////
    HealthBar* health_bar_friend = new HealthBar(m_player->getPMon());
    HealthBar* health_bar_enemy = new HealthBar(m_enemy->getPMon());
    health_bar_enemy->m_position.x = SCREEN_WIDTH-health_bar_enemy->m_size.x;

    m_player->setOnPmonChange([this, health_bar_friend](iPMon* _pmon)
    {
        health_bar_friend->setNewPmon(_pmon);
        updateAttackButtons();
    });
    m_enemy->setOnPmonChange([this, health_bar_enemy](iPMon* _pmon)
    {
        health_bar_enemy->setNewPmon(_pmon);
    });
    
    _scene.addNode(health_bar_friend);
    _scene.addNode(health_bar_enemy);
    ///////////////////////////////////////////////////////////////////////////////
    m_attack_buttons.resize(4);
    std::vector<iAttack*> friend_attacks = m_player->getPMon()->getAttacks();
    for (int i = 0; i < m_attack_buttons.size(); i++)
    {
        m_attack_buttons[i] = new DescriptiveButton();
        if (i < friend_attacks.size())
        {
            iAttack* attack = friend_attacks[i];
            m_attack_buttons[i]->setOnReleased([this, attack]
            {
                attack->useAttack(*m_enemy->getPMon(), *m_player->getPMon());
                setAttackButtonsVisible(false);
                m_turnstate = ENEMY_TURN;
                startTimer();
            });
            m_attack_buttons[i]->m_title = attack->getName();
            m_attack_buttons[i]->m_desc = attack->getDescription();
        }else
        {
            m_attack_buttons[i]->deactivate();
        }

        _scene.addNode(m_attack_buttons[i]);
    }

    
    
  
    // I could use modulo to make this in a per loop instead of hardcoding the value like I am here
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

    /////////////////////////////////////////////////////

    std::vector<iPMon*> pmon_list = m_player->getPMons();
    m_select_buttons.reserve(pmon_list.size());
    for (int i = 0; i < pmon_list.size(); i++)
    {
        iPMon* pmon = pmon_list[i];
        std::string name = pmon->getName();
        TextButton* text_button = new TextButton();
        text_button->m_text = name;
        text_button->m_position = se::Vec2((SCREEN_WIDTH-text_button->m_size.x)/2.0f, text_button->m_size.y*static_cast<float>(i+1));
        
        text_button->setOnReleased([this, i]
        {
            m_player->setPMonIndex(i);
        });

        m_select_buttons.push_back(text_button);
        _scene.addNode(text_button);
    }
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

void BattleManager::updateAttackButtons()
{
    std::vector<iAttack*> friend_attacks = m_player->getPMon()->getAttacks();
    
    for (int i = 0; i < m_attack_buttons.size(); i++)
    {
        if (i >= friend_attacks.size()){
            m_attack_buttons[i]->deactivate();
            m_attack_buttons[i]->m_title = "";
            m_attack_buttons[i]->m_desc = "";
            m_attack_buttons[i]->setOnReleased(nullptr);
            continue;
        }
        
        iAttack* attack = friend_attacks[i];
        m_attack_buttons[i]->setOnReleased([this, attack]
        {
            attack->useAttack(*m_enemy->getPMon(), *m_player->getPMon());
            setAttackButtonsVisible(false);
            m_turnstate = ENEMY_TURN;
            startTimer();
        });
        m_attack_buttons[i]->m_title = attack->getName();
        m_attack_buttons[i]->m_desc = attack->getDescription();
        m_attack_buttons[i]->activate();
    }
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
    for (TextButton* button : m_select_buttons)
    {
        button->visible = _visible;
    }
}


void BattleManager::_render()
{
    iNode::_render();
}
