#include "pimpl.hpp"

template <typename T>
pimpl<T>::pimpl():imp(T{})
{

}

template <typename T>
pimpl<T>::~pimpl()
{

}

template <typename T>
template <typename... Args>
pimpl<T>::pimpl(Args &&... args):imp(T{std::forward<Args>(args)...})
{

}

template <typename T>
T* pimpl<T>::operator->(){
    return imp.get();
}


template <typename T>
T& pimpl<T>::operator&(){
    return *imp.get();
}

