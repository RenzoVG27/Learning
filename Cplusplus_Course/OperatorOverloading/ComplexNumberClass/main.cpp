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

    const ComplexClass operator+(const ComplexClass& other){
        cout<<"sum 2 complexs"<<endl;
        return ComplexClass(this->real + other.real,this->imaginary + other.imaginary);
    }

    const ComplexClass operator+(const int value){
        cout<<"sum a integer"<<endl;
        return ComplexClass(this->real + value,this->imaginary);
    }
     

    inline int getReal() const {return real;}
    inline int getImaginary() const {return imaginary;}

};

ostream &operator<<(ostream &out,const ComplexClass &c){
    out<<"("<<c.getReal()<<","<<c.getImaginary()<<"j)"<<flush;
    return out;
}

ComplexClass operator+(const int &value, const ComplexClass &c){
    cout<<"operator firts value"<<endl;
    return ComplexClass(c.getReal() + value, c.getImaginary());
}

ComplexClass operator+(const ComplexClass &c,const int &value){//this is the same a the overloading funtion member
    cout<<"operator second value"<<endl;
    return ComplexClass(c.getReal() + value, c.getImaginary());
}

int main(int argc, char const *argv[])
{
   
   ComplexClass test1(3,5);
   test1.Print();

   ComplexClass test2(6,3);

    ComplexClass test3 = test1 + test2;

    test3.Print();

    cout<<test1<<endl;
    cout<<test2<<endl;

    cout<<3 + test2 + 5<<endl;

    return 0;
}
