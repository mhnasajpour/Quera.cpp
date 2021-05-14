#include "Octagonal.h"
#include <iostream>
using namespace std;

Octagonal::Octagonal(string _color, double _vertex[8][2])
{
    color = _color;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 2; j++)
            vertex[i][j] = _vertex[i][j];
}

void Octagonal::setColor(string _color){
    color = _color;
}

string Octagonal::getColor(){
    return color;
}

double Octagonal::perimeter()
{
    double sum = 0;

    for (int i = 0; i < 7; i++)
        sum += distance(vertex[i][0], vertex[i][1], vertex[i + 1][0], vertex[i + 1][1]);

    sum += distance(vertex[7][0], vertex[7][1], vertex[0][0], vertex[0][1]);
    return sum;
}

void Octagonal::diameter()
{
    int count = 0;
    double a[20];

    for (int i = 0; i < 6; i++)
        for (int j = i + 2; j < 8; j++)
        {
            if (i == 0 && j == 7)
                break;

            a[count] = distance(vertex[i][0], vertex[i][1], vertex[j][0], vertex[j][1]);
            count++;
        }

    for (int i = 0; i < 20; i++)
    {
        for (int j = i; j < 20; j++)
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

double Octagonal::area()
{
    double sum = 0;

    for (int i = 0; i < 8; i++)
        sum += vertex[i][0] * vertex[(i + 1) % 8][1];

    for (int i = 0; i < 8; i++)
        sum -= vertex[i][1] * vertex[(i + 1) % 8][0];

    return fabs(sum);
}