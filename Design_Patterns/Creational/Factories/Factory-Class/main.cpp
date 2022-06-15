#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Point {

    float x, y;

    Point (float x, float y):x(x),y(y){}

    

    

    class PointFactory{
        public:
        static Point CreateNewCartassian(float x, float y){
            return {x,y};
        }

        static Point CreateNewPolar(float rho, float tetha){
            return {rho * cos(tetha),rho * sin(tetha)};
        }
    };

    public:

    static PointFactory factory;

    friend ostream& operator<<(ostream &os, const Point & p){
        return os<<"x :"<<p.x<<", y :"<<p.y;
    }

    ~Point(){
        cout<<"Bye "<<this<<endl;
    }

};




int main(){


    auto p = Point::factory.CreateNewCartassian(100,2.5);
    cout<<p<<endl;

    auto p1 = Point::factory.CreateNewPolar(2.8,2.3);
    cout<<p1<<endl;


    return 0;
}