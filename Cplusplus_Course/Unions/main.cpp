#include <iostream>
#include <stdio.h>

struct vector2{
        int first;
        int second;
    };

    struct vector4{
            int first;
            int second;
            int third;
            int fourth;
        };

        struct test{
            vector2 a;
            vector2 b;
        };

void PrintVector2(vector2 newvector)
{   
    std::cout<<"first : "<<newvector.first<<", second: "<<newvector.second<<std::endl;
}

int main(int argc, char const *argv[])
{

struct parents
{
    union {//anonimus union
        int renzo;
        int marcia;
    };
};

parents newpar;

newpar.marcia = 25;

std::cout<<"renzo : "<<newpar.renzo<<", marcia: "<<newpar.marcia<<std::endl;
    
    

    union pile{
        vector4 mytest;
        test splitted;
    };


    pile mypile;
    vector4 myv4 = {1,2,3,4};
    mypile.mytest= myv4;

    PrintVector2(mypile.splitted.a); 
    PrintVector2(mypile.splitted.b); 

    


    return 0;
}
