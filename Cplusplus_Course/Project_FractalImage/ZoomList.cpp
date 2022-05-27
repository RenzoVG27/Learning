#include "ZoomList.h"
#include <iostream>

using namespace std;

ZoomList::ZoomList(int32_t width,int32_t height):m_width(width),m_height(height){

}
    
void ZoomList::add(const Zoom &zoom){
    m_zooms.push_back(zoom);

    m_xCenter += (zoom.x - m_width/2)*m_scale;
    m_yCenter += -(zoom.y - m_height/2)*m_scale;
    m_scale *= zoom.scale;

    cout<<m_xCenter<<", "<<m_yCenter<<", "<<m_scale<<std::endl;
    cout<<zoom.y<<", "<<m_height/2<<endl;
}

std::pair<double,double> ZoomList::doZoom(int32_t x,int32_t y){

    double xFractal = (x - m_width/2) * m_scale + m_xCenter;
    double yFractal = (y - m_height/2) * m_scale + m_yCenter;

    return std::pair<double,double>(xFractal,yFractal);
}