#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <math.h>

class Triangle
{
public:
    Triangle(double a0, double b0, double c0);
    double perimeter();
    double area();
private:
    double a,b,c;
};

#endif // TRIANGLE_H
