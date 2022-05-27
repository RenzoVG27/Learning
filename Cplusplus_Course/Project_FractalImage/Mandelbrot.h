#ifndef MANDELBROT_H_
#define MANDELBROT_H_

class Mandelbrot{
    public:
    Mandelbrot();
    virtual ~Mandelbrot();

    public:

    static const int MAX_ITERATIONS = 1000;
    static int getIterations(double x, double y);
};




#endif