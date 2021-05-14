#ifndef __Diamond
#define __Diamond

#include "Shapes.h"

class Diamond : public Shapes
{
private:
    double vertex[4][2];
    string color;

public:
    Diamond(string _color, double _vertex[4][2] = 0);
    double perimeter();
    void diameter();
    double area();
    void setColor(string _color);
    string getColor();
};

#endif