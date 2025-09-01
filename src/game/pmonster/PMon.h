#pragma once
#include <raylib.h>
#include <vector>

#include "PMonEnums.h"
#include "attack/Attack.h"



class PMon
{
protected:
    float m_hp = 50.0f;
    MonsterSide m_side;
public:
    PMon(float _max_hp, MonsterSide _side ): m_side(_side){m_hp = _max_hp;}
    
    virtual float getMaxHP(){return 50.0f;}
    
    virtual std::vector<Element> getElements() = 0;
    virtual std::vector<Attack*>  getAttacks() = 0;
    virtual std::vector<Texture2D*> getSprites() = 0; // Index 0 = Front | Index 1 = Back

    virtual MonsterSide getSide(){return m_side;}

    void damage(float _damage);
    virtual void _on_damage(float _damage){}
    
protected:
    
};
