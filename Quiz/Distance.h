#ifndef __Distance
#define __Distance

#include <iostream>
using namespace std;

class Distance
{
private:
    int yard;
    int feet;
    float inches;
    friend void check(Distance &);

public:
    Distance();
    Distance(int _yard, int _feet, float _inches);
    Distance(const Distance &);
    Distance &operator=(const Distance &);

    void setYard(int);
    void setFeet(int);
    void setInches(float);
    int getYard();
    int getFeet();
    float getInches();

    friend istream &operator>>(istream &, Distance &);
    friend ostream &operator<<(ostream &, Distance &);

    Distance operator+(const Distance &);
    Distance operator+(float _inches);
    Distance operator-(const Distance &);

    bool operator==(const Distance &);
    bool operator<(const Distance &);
    bool operator>(const Distance &);

    Distance &operator+=(const Distance &);
    Distance &operator+=(float _inches);
};

#endif