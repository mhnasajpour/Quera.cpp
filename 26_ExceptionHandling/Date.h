#ifndef __Date
#define __Date

#include <iostream>
#include <exception>
using namespace std;

class Date{
protected:
    int day;
    int month;
    int year;

public:
    Date(int day = 1, int month = 1, int year = 1973);

    void setDay(int);
    void setMonth(int);
    void setYear(int);

    int getDay();
    int getMonth();
    int getYear();
};

class DateException : public exception
{
private:
    int day, month, year;
    string message;

public:
    DateException(int _day, int _month, int _year);

    int getDay();
    int getMonth();
    int getYear();

    string what();
};

#endif