#include <iostream>
#include <memory>
using namespace std;

class Test{
    public:
    Test(){
        cout<<"Consttructor"<<endl;
    }
    ~Test(){
        cout<<"Destructor"<<endl;
    }
    void Print(){
        cout<<"Do something"<<endl;
    }
};

class cWithSP{
    private:
    unique_ptr<Test[]> spTest;

    public:
    cWithSP():spTest(new Test[3]){
        cout<<"Constructor of cWithSP"<<endl;
    }

    ~cWithSP(){
        cout<<"Destructor of cWithSP"<<endl;
    }

    void Print(){
        cout<<"Print !!!!"<<endl;
    }
};


int main(int argc, char const *argv[])
{
    {
        unique_ptr<Test[]> spTest (new Test[2]);

        spTest[1].Print();
    }
    cout<<"*************"<<endl;
    
    {
        cWithSP test2;
    }

    shared_ptr<Test> pTest1;//not able to use arrays in sahred pointer until c++17
            cout<<"Counter0 : "<<pTest1.use_count()<<endl;

    {
        shared_ptr<Test> pTest2 = make_shared<Test>();
        cout<<"Counter : "<<pTest2.use_count()<<endl;
        pTest1 = pTest2;
        cout<<"Counter2 : "<<pTest2.use_count()<<endl;

    }

    cout<<"Counter3 : "<<pTest1.use_count()<<endl;

    

    cout<<"Finished"<<endl;

     


    
    return 0;
}
