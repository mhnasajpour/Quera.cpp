#include "Date.h"
#include <stdexcept>

Date::Date(int _day, int _month, int _year)
{
    if (_day < 1 || _day > 31)
        throw _day;

    if (_month < 1 || _month > 12)
        throw out_of_range(to_string(_month));

    if (_year < 1973 || _year > 9999)
        throw DateException(day, month, year);

    day = _day;
    month = _month;
    year = _year;
}

void Date::setDay(int _day)
{
    if (_day < 1 || _day > 31)
        throw _day;

    day = _day;
}

void Date::setMonth(int _month)
{
    if (_month < 1 || _month > 12)
        throw out_of_range(to_string(_month));

    month = _month;
}

void Date::setYear(int _year)
{
    if (_year < 1973 || _year > 9999)
        throw DateException(day, month, year);

    year = _year;
}

int Date::getDay()
{
    return day;
}

int Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}

DateException::DateException(int _day, int _month, int _year)
{
    day = _day;
    month = _month;
    year = _year;
    message = "Invalid input";
}

int DateException::getDay()
{
    return day;
}

int DateException::getMonth()
{
    return month;
}

int DateException::getYear()
{
    return year;
}

string DateException::what()
{
    return message;
}