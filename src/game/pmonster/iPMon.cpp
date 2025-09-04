#include "iPMon.h"

#include <algorithm>

void iPMon::damage(float _damage)
{
    if (_on_damage(_damage))
    {
        m_damage_taken += _damage;
    }
    
}

void iPMon::heal(float _amount)
{
    m_damage_taken = std::clamp(m_damage_taken-_amount, 0.0f, getMaxHP());
}
