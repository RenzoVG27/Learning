#include <iostream>
#include <stdio.h>

using namespace std;

class ComplexClass{
    int real;
    int imaginary;

    public:

    ComplexClass():real(0),imaginary(0){

    }

    ComplexClass(int real, int imaginary):real(real),imaginary(imaginary){

    }

    void Print(){
        cout<<real<<"+"<<imaginary<<"j"<<endl;
    }

    /*bool operator==(const ComplexClass &other)const{
        return this->real == other.real && this->imaginary ==other.imaginary;
    }

    bool operator!=(const ComplexClass &other)const{
        return !(*this==other);
    }*/

    inline int getReal() const {return real;}
    inline int getImaginary() const {return imaginary;}

};

bool operator==(const ComplexClass &a,const ComplexClass &b){
    return a.getReal()==b.getReal() && a.getImaginary()==b.getImaginary();
}

bool operator!=(const ComplexClass &a,const ComplexClass &b){
    return !(a==b);
}


int main(int argc, char const *argv[])
{
   
   ComplexClass test1(3,5);
   ComplexClass test2(3,5);

   if(test1 == test2){
       cout<<"Equal"<<endl;
   }else{
       cout<<"Not Equal"<<endl;
   }
   
   if(test1 != test2){
       cout<<"Not Equal"<<endl;
   }else{
       cout<<"Equal"<<endl;
   }

    return 0;
}
