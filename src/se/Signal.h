#pragma once
#include <functional>
template <typename... Args>
class Signal
{
public:
    //Regesiter function pointer
    Signal& operator+=(std::function<void(Args...)>);
    void call(Args...);
    
protected:
    std::vector<std::function<void(Args...)>> m_func_register;
};
