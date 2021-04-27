#ifndef once
#define once

#include <iostream>
using namespace std;

class Fractional
{
private:
    int a, b; //   (a/b)

public:
    Fractional(int _a, int _b);
    Fractional operator+(const Fractional &);
    Fractional operator-(const Fractional &);
    Fractional operator*(const Fractional &);
    Fractional operator/(const Fractional &);
    int operator==(const Fractional &);
    int operator>(const Fractional &);
    Fractional &operator+=(const Fractional &);
    int operator[](int);
    friend ostream &operator<<(ostream &out, const Fractional &);
    
};

#endif