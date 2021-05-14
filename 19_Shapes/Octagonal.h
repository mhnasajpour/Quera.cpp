#ifndef __Octagonal
#define __Octagonal

#include "Shapes.h"

class Octagonal : public Shapes
{
private:
    double vertex[8][2];
    string color;

public:
    Octagonal(string _color, double _vertex[8][2] = 0);
    double perimeter();
    void diameter();
    double area();
    void setColor(string _color);
    string getColor();
};

#endif