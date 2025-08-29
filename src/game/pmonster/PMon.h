#pragma once
#include <raylib.h>
#include <vector>

#include "attack/Attack.h"


enum class Element
{
    
};

enum class MonsterSide
{
    FRIEND = 0,
    ENEMY
};

class PMon
{
protected:
    float m_hp = 50.0f;
    float m_max_hp = 50.0f;
    MonsterSide m_side;
public:
    PMon(float _max_hp, MonsterSide _side ): m_side(_side){m_hp = _max_hp;}
    
    virtual float getMaxHP(){return 50.0f;}
    
    virtual std::vector<Element> getElements() = 0;
    virtual std::vector<Attack*>  getAttacks() = 0;
    virtual std::vector<Texture2D*> getSprites() = 0;

    virtual MonsterSide getSide(){return m_side;}
    
protected:
    
};
