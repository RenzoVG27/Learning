#include "FractalCreator.h"
#include "Mandelbrot.h"

#include <math.h>
#include <iostream>

using namespace std;

FractalCreator::FractalCreator(int32_t width,int32_t height):
m_width(width),
m_height(height),
bitmap(new Bitmap(width,height)),
zoomList(new ZoomList(width,height)),
histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}),
fractal(new int[bitmap->getTotalPixel()]{0})
{
    zoomList->add(Zoom(m_width/2,m_height/2,2.0/m_width));
}

void FractalCreator::calculateIterators(){
    for(int row = 0;row<m_height;row++){
        for(int col = 0;col<m_width;col++){

            pair<double,double> fractalValues = zoomList->doZoom(col,row);

            int iterations = Mandelbrot::getIterations(fractalValues.first,fractalValues.second);
            fractal[row*m_width + col] = iterations;
            
            if(iterations==Mandelbrot::MAX_ITERATIONS)
                continue;
            
            histogram[iterations]++;
            
        }
    }
}

void FractalCreator::drawFractal(){

    
    
    int total = 0;
    for(int i = 0;i<Mandelbrot::MAX_ITERATIONS;i++){
        total+=histogram[i];
    }

    auto getRange = [](int value,vector<pair<double,RGB>> ranges){
        int count=0;
        for(auto range: ranges){
            if(((double)value)/Mandelbrot::MAX_ITERATIONS<range.first)
                break;
            count++;
        }
        return count;
    };

    for(int row = 0;row<m_height;row++){
        for(int col = 0;col<m_width;col++){

            int iterations = fractal[row*m_width + col];

            if(iterations==Mandelbrot::MAX_ITERATIONS)
                continue;

            double hue = 0.0;
            for(int i = 0;i<iterations;i++){
                hue += ((double)histogram[i])/total;
            }

            int ran = getRange(iterations,ranges);

            cout<<"Ran ="<<ran<<", hue: "<<hue<<endl;

            RGB startColor = ran==0? RGB(0,0,0): ranges.at(ran - 1).second;
            RGB endColor = ranges.at(ran).second;

            RGB diffColor = endColor - startColor;

            uint8_t red = diffColor.m_red * hue;
            uint8_t green = diffColor.m_green * hue;
            uint8_t blue = diffColor.m_blue * hue;

            bitmap->setPixel(col,row,{red,green,blue});

        }

    }
}

void FractalCreator::addZoom(const Zoom & zoom){
    zoomList->add(zoom);
}

void FractalCreator::writeBitmap(string name){
    bitmap->write(name);
}

void FractalCreator::run(string name){
    calculateIterators();
    drawFractal();
    writeBitmap(name);
}

void FractalCreator::addRange(double range,const RGB& rgb){
    ranges.push_back(pair<double,RGB>(range,rgb));
}