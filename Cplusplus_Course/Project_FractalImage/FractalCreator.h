#ifndef FRACTAL_CREATOR_H_
#define FRACTAL_CREATOR_H_

#include <cstdlib>
#include <string>
#include <memory>
#include <map>

#include "Zoom.h"
#include "ZoomList.h"
#include "Bitmap.h"
#include "RGB.h"

using namespace std;

class FractalCreator{
    public:
    FractalCreator(int32_t width,int32_t height);
    void addZoom(const Zoom & zoom);
    void run(string name);
    void addRange(double range,const RGB& rgb);

    private:

    void calculateIterators();
    void drawFractal();
    
    void writeBitmap(string name);
    vector<pair<double,RGB>> ranges;

    private:

    int32_t m_width;
    int32_t m_height;

    unique_ptr<ZoomList> zoomList;
    unique_ptr<Bitmap> bitmap;

    unique_ptr<int[]> histogram;
    unique_ptr<int[]> fractal;

};


#endif