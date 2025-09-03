#include "iPMon.h"

void iPMon::damage(float _damage)
{
    if (_on_damage(_damage))
    {
        m_damage_taken += _damage;
    }
    
}
