#include "Fractional.h"

int bmm(int a, int b)
{
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (a == 0)
        return b;

    b %= a;
    bmm(a, b);
}

Fractional::Fractional(int _a, int _b)
{
    a = _a;
    b = _b;
}

Fractional Fractional::operator+(const Fractional &frac)
{
    Fractional temp(0, 0);
    temp.b = (b * frac.b) / bmm(b, frac.b);
    temp.a = (temp.b / b) * a + (temp.b / frac.b) * frac.a;
    int t = bmm(temp.a, temp.b);
    temp.a /= t;
    temp.b /= t;
    return temp;
}

Fractional Fractional::operator-(const Fractional &frac)
{
    Fractional temp(0, 0);
    temp.b = (b * frac.b) / bmm(b, frac.b);
    temp.a = (temp.b / b) * a - (temp.b / frac.b) * frac.a;
    int t = bmm(temp.a, temp.b);
    temp.a /= t;
    temp.b /= t;
    return temp;
}

Fractional Fractional::operator*(const Fractional &frac)
{
    Fractional temp(0, 0);
    temp.a = a * frac.a;
    temp.b = b * frac.b;
    int t = bmm(temp.a, temp.b);
    temp.a /= t;
    temp.b /= t;
    return temp;
}

Fractional Fractional::operator/(const Fractional &frac)
{
    Fractional temp(0, 0);
    temp.a = a * frac.b;
    temp.b = frac.a * b;
    int t = bmm(temp.a, temp.b);
    temp.a /= t;
    temp.b /= t;
    return temp;
}

int Fractional::operator==(const Fractional &frac)
{
    return (a == frac.a && b == frac.b) ? 1 : 0;
}

int Fractional::operator>(const Fractional &frac)
{
    return ((float)a / b > (float)frac.a / frac.b) ? 1 : 0;
}

Fractional &Fractional::operator+=(const Fractional &frac)
{
    int kmm = (b * frac.b) / bmm(b, frac.b);
    a = (kmm / b) * a + (kmm / frac.b) * frac.a;
    int t = bmm(a, kmm);
    a /= t;
    kmm /= t;
    b = kmm;
    return *this;
}

int Fractional::operator[](int num)
{
    if (num == 0)
        return a;
    else if (num == 1)
        return b;
}

ostream &operator<<(ostream &out, const Fractional &frac)
{
    out << frac.a << "/" << frac.b;
    return out;
}