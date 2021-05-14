#include <iostream>
#include "Triangle.h"
#include "Triangle.cpp"
#include "Rectangle.h"
#include "Rectangle.cpp"
#include "Diamond.h"
#include "Diamond.cpp"
#include "Square.h"
#include "Square.cpp"
#include "Hexagonal.h"
#include "Hexagonal.cpp"
#include "Octagonal.h"
#include "Octagonal.cpp"
using namespace std;

template <typename T> // T: kind class (Triangle, Square, ...)
void setConstructor(Shapes **shape, int n, int set)
{ // n: index n of shape   set: number of points (Triangle => 3)(Square => 4)
    string color;
    cin >> color;

    getchar();
    getchar();

    double points[set][2];

    for (int i = 0; i < set; i++)
    {
        getchar();
        cin >> points[i][0];
        getchar();
        cin >> points[i][1];
    }

    shape[n] = new T(color, points);
}

int main()
{
    int n;
    cin >> n;

    Shapes **shape = new Shapes *[n];
    int *kind = new int[n];

    for (int i = 0; i < n; i++)
        cin >> kind[i];

    for (int i = 0; i < n; i++)
    {
        if (kind[i] == 1)
        {
            setConstructor<Triangle>(shape, i, 3);
        }
        else if (kind[i] == 2)
        {
            setConstructor<Rectangle>(shape, i, 4);
        }
        else if (kind[i] == 3)
        {
            setConstructor<Diamond>(shape, i, 4);
        }
        else if (kind[i] == 4)
        {
            setConstructor<Square>(shape, i, 4);
        }
        else if (kind[i] == 5)
        {
            setConstructor<Hexagonal>(shape, i, 6);
        }
        else if (kind[i] == 6)
        {
            setConstructor<Octagonal>(shape, i, 8);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << shape[i]->getColor() << " : ";
        printf("%0.2lf %0.2lf ", shape[i]->perimeter(), shape[i]->area());
        shape[i]->diameter();
        cout << endl;
    }
}