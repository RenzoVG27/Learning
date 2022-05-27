#include "Mandelbrot.h"
#include <math.h>
#include <complex>

using namespace std;

int Mandelbrot::getIterations(double x, double y){
    complex<double> z=0;
    complex<double> c(x,y);
    int iterations = 0;

    while(iterations<MAX_ITERATIONS && abs(z)<=2){
        
        z = z*z + c;

        iterations++;

    }

    return iterations;
}