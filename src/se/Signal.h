#pragma once
#include <functional>
#include <iostream>

namespace se
{

    template <typename... FArgs>
    class SignalFunction<FArgs...>
    {
        private:
        
    };





    
    template <typename... FArgs>
    class Signal
    {
        friend SignalFunction;
        
    public:
        //Regesiter function pointer
        Signal& operator+=(std::function<void(FArgs...)>);
        Signal& operator-=(std::function<void(FArgs...)>);
        void operator()(FArgs&&...);
        //void call(Args&&...);

        void clearRegister();
    protected:
        std::vector<std::function<void(FArgs...)>> m_func_register;
    };

}



/////////////////////Implementations/////////////////////////

template <typename ... FArgs>
se::Signal<FArgs...>& se::Signal<FArgs...>::operator+=(std::function<void(FArgs...)> _func_ptr)
{
    m_func_register.push_back(_func_ptr);
    return *this;
}
#pragma optimize("", off)
template <typename ... FArgs>
se::Signal<FArgs...>& se::Signal<FArgs...>::operator-=(std::function<void(FArgs...)> _func_ptr)
{
    for (int i = 0; i < m_func_register.size(); ++i)
    {
        if (*m_func_register[i].target<void(*)(FArgs...)>() == *_func_ptr.target<void(*)(FArgs...)>())
        {
            m_func_register.erase(std::next(m_func_register.begin(), i), std::next(m_func_register.begin(), i));
            return *this;
        }
    }
    std::cout << "Function Pointer not found.\n";
    return *this;
}
#pragma optimize("", on)
template <typename ... FArgs>
void se::Signal<FArgs...>::operator()(FArgs&&... args)
{
    for (auto func_ptr : m_func_register)
    {
        func_ptr(std::forward<FArgs>(args)...);
    }
}

template <typename ... FArgs>
void se::Signal<FArgs...>::clearRegister()
{

    m_func_register.clear();
}

