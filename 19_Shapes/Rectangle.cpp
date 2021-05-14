#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle(string _color, double _vertex[4][2])
{
    color = _color;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 2; j++)
            vertex[i][j] = _vertex[i][j];
}

void Rectangle::setColor(string _color)
{
    color = _color;
}

string Rectangle::getColor()
{
    return color;
}

double Rectangle::perimeter()
{
    double sum = 0;
    sum += distance(vertex[0][0], vertex[0][1], vertex[1][0], vertex[1][1]);
    sum += distance(vertex[1][0], vertex[1][1], vertex[2][0], vertex[2][1]);

    return (sum * 2);
}

void Rectangle::diameter()
{
    double a = distance(vertex[0][0], vertex[0][1], vertex[2][0], vertex[2][1]);
    printf("%0.2lf %0.2lf", a, a);
}

double Rectangle::area()
{
    double a = distance(vertex[0][0], vertex[0][1], vertex[1][0], vertex[1][1]);
    double b = distance(vertex[1][0], vertex[1][1], vertex[2][0], vertex[2][1]);
    return a * b;
}