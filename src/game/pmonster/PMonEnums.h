#pragma once
#include <vector>

#include "../consts.h"




enum class MonsterSide
{
    FRIEND = 0,
    ENEMY
};


enum Element
{
    NORMAL = 0,
    FIRE,
    WATER,
    GRASS,
    ELECTRIC,
    STEEL,
};

class cElement
{
public:
    enum 
    {
        NORMAL = 0,
        FIRE,
        WATER,
        GRASS,
        ELECTRIC,
        STEEL,
    };
    static float GetElementsMultiplier(std::vector<Element> _attacking, std::vector<Element> _defending)
    {
        std::vector<float> multiplier_list;
        for (Element attacker: _attacking)
        {
            for (Element defender: _defending)
            {
                multiplier_list.push_back(ELEMENT_TABLE[attacker][defender]);
            } 
        }
        float finalMultiplier = 1.0f;
        for (float multiplier: multiplier_list)
        {
            finalMultiplier *= multiplier;
        }

        return finalMultiplier;
    }
};