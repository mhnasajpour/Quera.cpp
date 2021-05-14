#ifndef __Hexagonal
#define __Hexagonal

#include "Shapes.h"

class Hexagonal : public Shapes
{
private:
    double vertex[6][2];
    string color;

public:
    Hexagonal(string _color, double _vertex[6][2] = 0);
    double perimeter();
    void diameter();
    double area();
    void setColor(string _color);
    string getColor();
};

#endif