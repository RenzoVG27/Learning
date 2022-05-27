#ifndef BIT_MAP_H_
#define BIT_MAP_H_

#include <string>
#include <cstdint>
#include <memory>

using namespace std;

//#pragma pack(2)

struct sRGB{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

class Bitmap{

    private:
    int32_t m_width;
    int32_t m_height;
    unique_ptr<uint8_t[]> m_pPixels{nullptr};

    public:

    Bitmap(int32_t width, int32_t height);
    bool write(string filename);
    void setPixel(int32_t x, int32_t y, sRGB color);
    virtual ~Bitmap();
    inline int32_t getTotalPixel(){return m_width*m_height;}

};




#endif