#ifndef __Square
#define __Square

#include "Shapes.h"

class Square : public Shapes
{
private:
    double vertex[4][2];
    string color;

public:
    Square(string _color, double _vertex[4][2] = 0);
    double perimeter();
    void diameter();
    double area();
    void setColor(string _color);
    string getColor();
};

#endif