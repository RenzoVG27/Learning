#ifndef ZOOM_LIST_H_
#define ZOOM_LIST_H_

#include <cstdlib>
#include <utility>
#include <vector>

#include "Zoom.h"

class ZoomList{
    private:
    int32_t m_width{0};
    int32_t m_height{0};

    double m_xCenter{0};
    double m_yCenter{0};
    double m_scale{1.0};
    std::vector<Zoom> m_zooms;

    public:
    ZoomList(int32_t width,int32_t height);
    void add(const Zoom &zoom);
    std::pair<double,double> doZoom(int32_t x,int32_t y);


};

#endif