#ifndef __Triangle
#define __Triangle

#include "Shapes.h"

class Triangle : public Shapes
{
private:
    double vertex[3][2];
    string color;

public:
    Triangle(string _color, double _vertex[3][2] = 0);
    double perimeter();
    void diameter();
    double area();
    void setColor(string _color);
    string getColor();
};

#endif