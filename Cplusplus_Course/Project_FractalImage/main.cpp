#include <iostream>
#include <stdio.h>
#include <math.h>

#include "FractalCreator.h"
#include "RGB.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int static WIDTH = 800;
    int static HEIGHT = 600;

   FractalCreator fractalCreator(WIDTH,HEIGHT);

    fractalCreator.addRange(0.0,RGB(0,0,0));  
    fractalCreator.addRange(0.3,RGB(255,0,0));
    fractalCreator.addRange(0.5,RGB(255,255,0));
    fractalCreator.addRange(1.0,RGB(255,255,255));

    fractalCreator.addZoom(Zoom(251,47,0.1));
    //fractalCreator.addZoom(Zoom(234,202,0.1));

   fractalCreator.run("newBMP.bmp");    
   

   

    return 0;
}
