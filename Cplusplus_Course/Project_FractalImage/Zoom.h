#ifndef ZOOM_H_
#define ZOOM_H_

#include <cstdlib>

struct Zoom{
    int32_t x{0};
    int32_t y{0};
    double scale{1.0};
    Zoom(int32_t x,int32_t y,double scale):x(x),y(y),scale(scale){
        
    }
};

#endif