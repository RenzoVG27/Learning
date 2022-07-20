#pragma once

#include "pimpl.hpp"

using namespace std;

class Person{
    

    class imp;
    pimpl<imp> imple;
    
};