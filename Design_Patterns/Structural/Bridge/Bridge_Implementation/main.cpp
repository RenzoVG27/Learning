#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <memory>

using namespace std;

//two clases of objects
//circle, square
//calculate area, calculare perimeter

//2x2 areasquare,area circle, perimeter square, perimeter circle


struct preparation{
    virtual void chicken_prep() = 0;
    virtual void pork_prep() = 0;
};

struct fastfood : preparation{
    void chicken_prep() override{
        cout<<"Full of oil, add some fries and also a soda"<<endl;
    }

    void pork_prep() override{
        cout<<"Full of oil, add some sweet potates and also a tamal with coffee"<<endl;
    }
};


struct dietetic : preparation{
    void chicken_prep() override{
        cout<<"turn on the grill, no oil, add some lettuce and tomato and orange juice"<<endl;
    }

    void pork_prep() override{
        cout<<"boiled pork, carrots and water"<<endl;
    }
};


struct food {
    preparation &prep;

    food (preparation &prep):prep{prep}
    {

    }

    virtual void prepare() = 0;

};

struct chicken : food{
    chicken(preparation &prep):food(prep){

    }

    void prepare(){
        prep.chicken_prep();
    }
};

struct pork : food{
    pork(preparation &prep):food(prep){

    }

    void prepare(){
        prep.pork_prep();
    }
};


int main(){

   fastfood prepa;

   pork mysundayPork(prepa);

   mysundayPork.prepare();

   dietetic prepa2;

   chicken mychick(prepa2);
   mychick.prepare();


    return 0;
}