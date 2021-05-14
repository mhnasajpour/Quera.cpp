#ifndef __Rectangle
#define __Rectangle

#include "Shapes.h"

class Rectangle : public Shapes
{
private:
    double vertex[4][2];
    string color;

public:
    Rectangle(string _color, double _vertex[4][2] = 0);
    double perimeter();
    void diameter();
    double area();
    void setColor(string _color);
    string getColor();
};

#endif