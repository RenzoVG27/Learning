#ifndef RGB_H
#define RGB_H

#include <cstdlib>
#include <ostream>

using namespace std;

class RGB{

    public:

    RGB(uint8_t red,uint8_t green,uint8_t blue);

    const RGB operator-(const RGB& other);

    friend ostream &operator<<(ostream & out, const RGB& other);

    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;

    private:

    

};





#endif