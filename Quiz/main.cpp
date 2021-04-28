#include "Space.h"
#include <iostream>
using namespace std;

int main()
{
    Space a;
    cin >> a;
    Space b = a;
    cout << b << endl;
    b += a;
    cout << b << endl;
    Space c = a + b;
    cout << c << endl;
    if (c == Space(1, 1, 141))
    {
        cout << "Is equal :)" << endl;
    }

    c = c - Space(3, 1, 18);
    c += 4;
    cout << c << endl;
}