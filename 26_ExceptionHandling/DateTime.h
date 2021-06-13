#ifndef DateTime___
#define DateTime___

#include "Date.h"
#include "Time.h"

class DateTime : public Date, public Time
{
public:
    DateTime(int _day, int _month, int _year, int _hour, int _minute);
};

class DateTimeException : public exception
{
private:
    int error;
    string message;

public:
    DateTimeException(int error, string what);

    int getError();
    string what();
};

#endif