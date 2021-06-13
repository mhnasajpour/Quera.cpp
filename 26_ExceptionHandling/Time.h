#ifndef __Time
#define __Time

#include <iostream>
#include <exception>
using namespace std;

class Time
{
protected:
    int hour;
    int minute;

public:
    Time(int hour = 0, int minute = 0);

    void setHour(int _hour);
    void setMinute(int _minute);

    int getHour();
    int getMinute();
};

class TimeException : public exception
{
private:
    int hour, minute;
    string message;

public:
    TimeException(int hour, int minute);

    int getHour();
    int getMinute();

    string what();
};

#endif