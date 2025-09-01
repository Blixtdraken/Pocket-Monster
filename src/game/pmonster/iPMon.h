#pragma once
#include <raylib.h>
#include <vector>

#include "PMonEnums.h"
#include "attack/iAttack.h"



class iPMon
{
protected:
    float m_hp = 50.0f;
    MonsterSide m_side;
public:
    iPMon(MonsterSide _side ): m_side(_side){}
    
    virtual float getMaxHP() = 0;
    
    virtual std::vector<Element> getElements() = 0;
    virtual std::vector<iAttack*>  getAttacks() = 0;
    virtual std::vector<Texture2D*> getSprites() = 0; // Index 0 = Front | Index 1 = Back

    virtual MonsterSide getSide(){return m_side;}

    void damage(float _damage);
    virtual void _on_damage(float _damage){}
    
protected:
    
};
