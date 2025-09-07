#pragma once
#include "interfaces/iNode.h"
#include "interfaces/iScene.h"
#include "nodes/DescriptiveButton.h"
#include "nodes/PMonNode.h"
#include "nodes/TextButton.h"



class BattleManager : public se::iNode //iNode for it to tick
{

    
protected:
    
    void startTimer();
    void handlePlayerTurn();
    void handleEnemyTurn();
    void setAttackButtonsVisible(bool _visible);
    void setSelectButtonsVisible(bool _visible);
    void handleDeadPlayer();
    void handleDeadEnemy();
    void updateAttackButtons();
    
    enum TurnState
    {
        PLAYER_TURN = 0,
        ENEMY_TURN,
        WON,
        LOST,
    };
    bool m_is_selecting = false;
    bool m_animating = false;
    float m_timer = 0.0f;
    TurnState m_turnstate = PLAYER_TURN;
    PMonNode* m_player;
    PMonNode* m_enemy;
    TextButton* m_switch_pmon;
    
    
    std::vector<DescriptiveButton*> m_attack_buttons;
    std::vector<TextButton*> m_select_buttons;
public:
    //BattleManager(PMonNode* _player, PMonNode* _enemy, std::vector<DescriptiveButton> _attack_buttons, std::vector<TextButton> _pmon_buttons):m_player(_player), m_enemy(_enemy), m_pmon_buttons(_pmon_buttons), m_attack_buttons(_attack_buttons){}
    BattleManager(se::iScene& _scene);
    
    
    void _ready() override;
    void _handleInput() override;
    void _update(double _deltaTime) override;
    void _render() override;
};
