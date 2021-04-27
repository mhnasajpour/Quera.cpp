#include "Polynomial.h"
#include <iostream>
using namespace std;

int main()
{
    Polynomial p1, p2;
    cin >> p1 >> p2;
    Polynomial p3 = p1 * p2, p4;
    p4 = 2 - p1;
    cout << p1 + p2 << endl;
    cout << p4 << endl;
    cout << p3 << endl;
    cout << p2 * 3 << endl;
    cout << p1 / p2 << endl;
    cout << p1 % p2 << endl;
    return 0;
}

// p1 = +3x^7+18x^6-3x^3+x+19
// p2 = +x^5+x^4-x-1
// p3 = +3x^12+21x^11+18x^10-6x^8-24x^7-17x^6+20x^5+22x^4+3x^3-x^2-20x-19
// p4 = -3x^7-18x^6+3x^3-x-17

// p1+p2 = +3x^7+18x^6+x^5+x^4-3x^3+18
// p1/p2 = +3x^2+15x-15
// p1%p2 =+15x^4+18x^2+x+4