
#pragma once

#include <ostream>

using namespace std;

enum class Material;

class Product{
    public:

    int walls;
    int windows;
    int doors;

    Material mate;

    friend ostream & operator<<(ostream &obj,const Product &other){
        return obj<<"Product :  doors="<<other.doors<<", Walls="<<other.walls<<", Windows="<<other.windows<<endl;
    }
};