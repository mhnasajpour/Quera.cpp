#include "Professor.h"
#include "Person.h"

#include <iostream>
using namespace std;

int Professor::setId = 0;

Professor::Professor()
{
    curId = ++setId;
}

void Professor::getdata()
{
    cin >> name;
    cin >> age;
    cin >> publications;
}

void Professor::putdata()
{
    cout << name << ' ';
    cout << age << ' ';
    cout << publications << ' ';
    cout << curId << endl;
}