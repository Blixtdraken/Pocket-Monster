#include "Signal.h"

template <typename ... Args>
Signal<Args...>& Signal<Args...>::operator+=(std::function<void(Args...)> _func_ptr)
{
    this->m_func_register.push_back(_func_ptr);
}

template <typename ... Args>
void Signal<Args...>::call(Args... args)
{
    for (auto func_ptr : m_func_register)
    {
        func_ptr(args);
    }
}
