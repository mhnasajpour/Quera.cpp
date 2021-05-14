#include "Triangle.h"
#include <iostream>
using namespace std;

Triangle::Triangle(string _color, double _vertex[3][2])
{
    color = _color;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            vertex[i][j] = _vertex[i][j];
}

void Triangle::setColor(string _color)
{
    color = _color;
}

string Triangle::getColor()
{
    return color;
}

double Triangle::perimeter()
{
    double sum = 0;
    sum += distance(vertex[0][0], vertex[0][1], vertex[1][0], vertex[1][1]);
    sum += distance(vertex[0][0], vertex[0][1], vertex[2][0], vertex[2][1]);
    sum += distance(vertex[1][0], vertex[1][1], vertex[2][0], vertex[2][1]);
    return sum;
}

void Triangle::diameter()
{
    return;
}

double Triangle::area()
{
    double peri = perimeter() / 2;
    double a = distance(vertex[0][0], vertex[0][1], vertex[1][0], vertex[1][1]);
    double b = distance(vertex[0][0], vertex[0][1], vertex[2][0], vertex[2][1]);
    double c = distance(vertex[1][0], vertex[1][1], vertex[2][0], vertex[2][1]);
    return sqrt(peri * (peri - a) * (peri - b) * (peri - c));
}