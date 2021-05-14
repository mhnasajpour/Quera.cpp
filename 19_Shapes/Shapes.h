#ifndef __Shapes
#define __Shapes

#include <cmath>
#include <iostream>
using namespace std;

class Shapes
{
public:
    virtual double perimeter() = 0;
    virtual void diameter() = 0;
    virtual double area() = 0;
    virtual string getColor() = 0;
    virtual void setColor(string _color) = 0;
};

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

#endif