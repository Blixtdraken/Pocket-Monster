#include "BattleManager.h"

#include "SceneManager.h"
#include "Signal.h"
#include "nodes/HealthBar.h"
#include "pmonster/children/Branchey.h"
#include "pmonster/children/Gumboo.h"



BattleManager::BattleManager(se::iScene& _scene)
{

    m_player = new PMonNode({
        new Branchey(),
        new Gumboo(),
    }, MonsterSide::FRIEND);
    
    m_enemy = new PMonNode({
        new Gumboo(),
        new Branchey(),
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
        _scene.addNode(m_attack_buttons[i]);
    }   
    updateAttackButtons();
    
    
  
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

    m_switch_pmon = new TextButton();
    m_switch_pmon->s_on_released += [this]
    {
        setSelectButtonsVisible(!m_select_buttons[0]->visible); // Toggle visibility and all should always be same visbility but incase they're not this line does also kinda of fix it.
        //se::SceneManager::GetInstance().changeScene(new BattleScene()); // Badly designed to change scene so I'm doo dooed
    };
    m_switch_pmon->m_position.x = (SCREEN_WIDTH-m_switch_pmon->m_size.x)/2.0f;
    m_switch_pmon->m_text = "Switch Pokemon";
    _scene.addNode(m_switch_pmon);
    std::vector<iPMon*> pmon_list = m_player->getPMons();
    m_select_buttons.reserve(pmon_list.size());
    for (int i = 0; i < pmon_list.size(); i++)
    {
        iPMon* pmon = pmon_list[i];
        std::string name = pmon->getName();
        TextButton* text_button = new TextButton();
        text_button->m_text = name;
        text_button->m_position = se::Vec2((SCREEN_WIDTH-text_button->m_size.x)/2.0f, text_button->m_size.y*(static_cast<float>(i+1)+0.5f));
        
        text_button->s_on_released += [this, i, text_button]
        {
            if (m_player->getPMonIndex() == i) return;
            m_player->setPMonIndex(i);
            setSelectButtonsVisible(false);
            text_button->activate();
        };
        text_button->visible = false;
        m_select_buttons.push_back(text_button);
        _scene.addNode(text_button);
    }

    
}

void BattleManager::test(int nun, std::string text){}

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



void BattleManager::_update(double _deltaTime)
{
    
    
    if (m_animating)
    {
        m_timer += _deltaTime;
        if (m_timer > ANIMATION_TIME) m_animating = false;
        else return;
    }
    
    if (m_is_selecting) return;

    
    
    
    
    switch(m_turnstate)
    {
    case PLAYER_TURN:
        handleDeadPlayer();
        if (!m_player->getPMon()->getIsAlive()) return;
        handlePlayerTurn();
       break;
    case ENEMY_TURN:
        handleDeadEnemy();
        handleEnemyTurn();
        break;
    }
}

void BattleManager::handleDeadPlayer()
{
    //TODO: Chekc player health and enemey health and then trigger m_selecing = true thingies
    if (!m_player->getPMon()->getIsAlive())
    {
        m_switch_pmon->deactivate();
        setSelectButtonsVisible(true);
    }
}
void BattleManager::handleDeadEnemy()
{
    if (!m_enemy->getPMon()->getIsAlive())
    {
        
    }
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
            //m_attack_buttons[i]->setOnReleased(nullptr); // TODO: FIX REMOVE
            continue;
        }
        
        iAttack* attack = friend_attacks[i];

        if (!attack->getAvailable()) m_switch_pmon->deactivate();   
        std::function<void()> func_ptr = [this, attack]
        {
            attack->useAttack(*m_enemy->getPMon(), *m_player->getPMon());
            setAttackButtonsVisible(false);
            setSelectButtonsVisible(false);
            m_switch_pmon->deactivate();
            m_turnstate = ENEMY_TURN;
            startTimer();
        };
        m_attack_buttons[i]->s_on_released -= func_ptr;
        m_attack_buttons[i]->s_on_released += func_ptr;
        m_attack_buttons[i]->m_title = attack->getName();
        m_attack_buttons[i]->m_desc = attack->getDescription();
        m_attack_buttons[i]->activate();
    }
}


void BattleManager::handlePlayerTurn()
{
    setAttackButtonsVisible(true);
    m_switch_pmon->activate();
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
    
    

    //Self explanatory c:
    for (int i = 0; i < m_select_buttons.size(); i++)
    {
        TextButton* button = m_select_buttons[i];
        iPMon* related_pmon = m_player->getPMons()[i];
        if (_visible)
        {
            //If pokemon used, disable button otherwise disable based on alive.

            if (i == m_player->getPMonIndex())
            {
                button->deactivate();
            }else
            {
                button->active = related_pmon->getIsAlive();
            }
            

        }
        
        button->visible = _visible;
    }
}


void BattleManager::_render()
{
    iNode::_render();
}
