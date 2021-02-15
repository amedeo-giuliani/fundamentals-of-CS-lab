#include "triangle.h"

Triangle::Triangle(double a0, double b0, double c0)
{
    a = a0;
    b = b0;
    c = c0;
}

double Triangle::perimeter()
{
    return a+b+c;
}

double Triangle::area()
{
    double sp = perimeter()/2;
    double area = sqrt( sp * (sp - a) * (sp - b) * (sp - a));
    return area;
}
