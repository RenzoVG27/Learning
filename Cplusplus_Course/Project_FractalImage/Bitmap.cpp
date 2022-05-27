#include "Bitmap.h"
#include "BitMapFileHeader.h"
#include "BitMapInfoHeader.h"

#include <fstream>
#include <iostream>

using namespace fractal;
using namespace std;

Bitmap::Bitmap(int32_t width, int32_t height):m_width(width),m_height(height),m_pPixels(new uint8_t[width*height*3]{}){

}

bool Bitmap::write(string filename){

    sBitMapInfoHeader infoHeader;
    sBitMapFileHeader fileHeader;

    infoHeader.width = m_width;
    infoHeader.height = m_height;
    infoHeader.dataSize = m_width*m_height*3;

    fileHeader.fileSize = sizeof(sBitMapFileHeader) + sizeof(sBitMapInfoHeader) + m_width*m_height*3;
    fileHeader.dataOffset = sizeof(sBitMapFileHeader) + sizeof(sBitMapInfoHeader);

    ofstream file;
    file.open(filename.c_str(),ios::out|ios::binary);
    if(!file)
    {
        return false;
    }

    //cout<<"Add : "<<&fileHeader<<endl;

    file.write((char*)&fileHeader,sizeof(fileHeader));
    file.write((char*)&infoHeader,sizeof(infoHeader));
    file.write((char*)m_pPixels.get(),m_width*m_height*3);


    file.close();
    if(!file)
    {
        return false;
    }

    return true;
}

void Bitmap::setPixel(int32_t x, int32_t y, sRGB color){

    uint8_t * pixel = m_pPixels.get() + (y*3)*m_width + (x*3);

    *(pixel + 0) = color.blue;
    *(pixel + 1) = color.green;
    *(pixel + 2) = color.red;

}

Bitmap::~Bitmap(){

}