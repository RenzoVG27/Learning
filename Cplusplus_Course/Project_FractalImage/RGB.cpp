#include "RGB.h"

using namespace std;

RGB::RGB(uint8_t red,uint8_t green,uint8_t blue):m_red(red),m_green(green),m_blue(blue){

}

const RGB RGB::operator-(const RGB& other){

    return RGB(this->m_red-other.m_red,this->m_green-other.m_green,this->m_blue-other.m_blue);

}

ostream& operator<<(ostream& out, const RGB& other){
    out<<"red: "<<(int)other.m_red<<", green: "<<(int)other.m_green<<", blue:"<<(int)other.m_blue<<endl;
    return out;
}