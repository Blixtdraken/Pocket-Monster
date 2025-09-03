#pragma once
#include <raylib.h>
#include <vector>

#include "PMonEnums.h"
#include "attack/iAttack.h"



class iPMon
{
protected:
    float m_damage_taken = 0.0f;
public:
    iPMon(){}
    
    virtual float getMaxHP() = 0;
    float getHP(){return getMaxHP()-m_damage_taken;}
    bool getIsAlive(){return (getMaxHP()>m_damage_taken);}
    
    virtual const std::string getName() = 0;
    
    virtual std::vector<Element> getElements() = 0;
    virtual std::vector<iAttack*>  getAttacks() = 0;
    virtual std::vector<Texture2D> getSprites() = 0; // Index 0 = Front | Index 1 = Back
    
    
    

    void damage(float _damage);
    virtual bool _on_damage(float _damage){return true;} // Should return if damage should apply
    

protected:
    
};
