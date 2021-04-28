#include "Distance.h"
#include <iostream>
using namespace std;

int main()
{
    Distance a;
    cin >> a;
    Distance b = a;
    cout << b << endl;
    b += a;
    cout << b << endl;
    Distance c = a + b;
    cout << c << endl;
    if (c == Distance(1, 1, 141))
    {
        cout << "Is equal :)" << endl;
    }

    c = c - Distance(3, 1, 18);
    c += 4;
    cout << c << endl;
}