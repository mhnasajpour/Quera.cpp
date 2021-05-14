#include "Hexagonal.h"
#include <iostream>
using namespace std;

Hexagonal::Hexagonal(string _color, double _vertex[6][2])
{
    color = _color;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 2; j++)
            vertex[i][j] = _vertex[i][j];
}

void Hexagonal::setColor(string _color)
{
    color = _color;
}

string Hexagonal::getColor()
{
    return color;
}

double Hexagonal::perimeter()
{
    double sum = 0;

    for (int i = 0; i < 5; i++)
        sum += distance(vertex[i][0], vertex[i][1], vertex[i + 1][0], vertex[i + 1][1]);

    sum += distance(vertex[5][0], vertex[5][1], vertex[0][0], vertex[0][1]);
    return sum;
}

void Hexagonal::diameter()
{
    int count = 0;
    double a[9];

    for (int i = 0; i < 4; i++)
        for (int j = i + 2; j < 6; j++)
        {
            if (i == 0 && j == 5)
                break;

            a[count] = distance(vertex[i][0], vertex[i][1], vertex[j][0], vertex[j][1]);
            count++;
        }

    for (int i = 0; i < 9; i++)
    {
        for (int j = i; j < 9; j++)
        {
            if (a[i] < a[j])
            {
                double temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        printf("%0.2lf ", a[i]);
    }
}

double Hexagonal::area()
{
    double sum = 0;

    for (int i = 0; i < 6; i++)
        sum += vertex[i][0] * vertex[(i + 1) % 6][1];

    for (int i = 0; i < 6; i++)
        sum -= vertex[i][1] * vertex[(i + 1) % 6][0];

    return fabs(sum);
}