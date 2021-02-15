#include "ellipse.h"
#include <math.h>

Ellipse::Ellipse(double a0, double b0)
{
    a = a0;
    b = b0;
}

double Ellipse::area()
{
    A = 3.14 * a * b;
    return A;
}

double Ellipse::focal_dist(){
    fd = 2.0 * sqrt(pow(a,2) - pow(b,2));
    return fd;
}
