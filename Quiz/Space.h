#ifndef __SPACE
#define __SPACE

#include <iostream>
using namespace std;

class Space
{
private:
    int yard;
    int feet;
    float inches;
    friend void check(Space &);

public:
    Space();
    Space(int _yard, int _feet, float _inches);
    Space(const Space &);
    Space &operator=(const Space &);

    void setYard(int);
    void setFeet(int);
    void setInches(float);
    int getYard();
    int getFeet();
    float getInches();

    friend istream &operator>>(istream &, Space &);
    friend ostream &operator<<(ostream &, Space &);

    Space operator+(const Space &);
    Space operator+(float _inches);
    Space operator-(const Space &);

    bool operator==(const Space &);
    bool operator<(const Space &);
    bool operator>(const Space &);

    Space &operator+=(const Space &);
    Space &operator+=(float _inches);
};

#endif