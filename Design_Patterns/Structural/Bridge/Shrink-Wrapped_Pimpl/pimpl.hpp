#pragma once
#include <memory>

using namespace std;

template <typename T> class pimpl{

    unique_ptr<T> imp;

    public:
    pimpl();
    ~pimpl();

    template<typename... Args>
    pimpl(Args&&...arg);

    T* operator->();
    T& operator&();

};