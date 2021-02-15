#ifndef ELLIPSE_H
#define ELLIPSE_H

class Ellipse
{
public:
    Ellipse(double a0, double b0);
    double area();
    double focal_dist();
private:
    double a, b;
    double A, fd;
};

#endif // ELLIPSE_H
