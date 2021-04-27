#ifndef __Polynomial
#define __Polynomial

#include <iostream>
using namespace std;

class Polynomial
{
private:
    int zarib[21];
    void proccess_str(string, int);

public:
    Polynomial();
    Polynomial(int);
    Polynomial(const Polynomial &);

    Polynomial operator=(Polynomial);
    friend Polynomial operator-(Polynomial &);

    Polynomial operator+(const Polynomial &);
    Polynomial operator-(const Polynomial &);
    Polynomial operator*(const Polynomial &);

    Polynomial operator++(int);
    Polynomial &operator++();

    friend istream &operator>>(istream &, Polynomial &);
    friend ostream &operator<<(ostream &, Polynomial);

    friend Polynomial operator+(int, const Polynomial &);
    friend Polynomial operator-(int, const Polynomial &);
    friend Polynomial operator*(int, const Polynomial &);

    Polynomial operator/(Polynomial);
    Polynomial operator%(Polynomial);
};

#endif