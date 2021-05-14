#include "Square.h"
#include <iostream>
using namespace std;

Square::Square(string _color, double _vertex[4][2])
{
    color = _color;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 2; j++)
            vertex[i][j] = _vertex[i][j];
}

void Square::setColor(string _color)
{
    color = _color;
}

string Square::getColor()
{
    return color;
}

double Square::perimeter()
{
    double sum = distance(vertex[0][0], vertex[0][1], vertex[1][0], vertex[1][1]);

    return (sum * 4);
}

void Square::diameter()
{
    double a = distance(vertex[0][0], vertex[0][1], vertex[2][0], vertex[2][1]);

    printf("%0.2lf %0.2lf", a, a);
}

double Square::area()
{
    double a = distance(vertex[0][0], vertex[0][1], vertex[1][0], vertex[1][1]);

    return (a * a);
}