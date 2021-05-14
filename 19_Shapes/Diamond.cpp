#include "Diamond.h"
#include <iostream>
using namespace std;

Diamond::Diamond(string _color, double _vertex[4][2])
{
    color = _color;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 2; j++)
            vertex[i][j] = _vertex[i][j];
}

void Diamond::setColor(string _color)
{
    color = _color;
}

string Diamond::getColor()
{
    return color;
}

double Diamond::perimeter()
{
    double sum = distance(vertex[0][0], vertex[0][1], vertex[1][0], vertex[1][1]);

    return (sum * 4);
}

void Diamond::diameter()
{
    double a = distance(vertex[0][0], vertex[0][1], vertex[2][0], vertex[2][1]);
    double b = distance(vertex[1][0], vertex[1][1], vertex[3][0], vertex[3][1]);
    if (a > b)
        printf("%0.2lf %0.2lf", a, b);
    else
        printf("%0.2lf %0.2lf", b, a);
}

double Diamond::area()
{
    double a = distance(vertex[0][0], vertex[0][1], vertex[2][0], vertex[2][1]);
    double b = distance(vertex[1][0], vertex[1][1], vertex[3][0], vertex[3][1]);

    return (a * b) / 2;
}