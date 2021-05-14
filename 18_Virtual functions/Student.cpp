#include "Student.h"
#include "Person.h"

#include <iostream>
using namespace std;

int Student::setId = 0;

Student::Student()
{
    curId = ++setId;
}

void Student::getdata()
{
    cin >> name;
    cin >> age;

    for (int i = 0; i < 6; i++)
        cin >> mark[i];
}

void Student::putdata()
{
    cout << name << ' ';
    cout << age << ' ';

    int sum = mark[0];
    for (int i = 1; i < 6; i++)
        sum += mark[i];

    cout << sum << ' ';
    cout << curId << endl;
}