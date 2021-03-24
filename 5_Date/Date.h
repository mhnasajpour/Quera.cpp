#include <iostream>
#include <stdbool.h>
#include <string.h>
using namespace std;

#ifndef once
#define once

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int _year, int _month, int _day);
    void SetDate(int _year, int _month, int _day);
    void SetYear(int _year);
    void SetMonth(int _month);
    void SetDay(int _day);

    int GetYear() const;
    const char *GetMonth() const;

    void Print() const;

    Date &NextDay();
    Date &PreviousDay();
    Date &NextMonth();
    Date &PreviousMonth();
    Date &NextYear();
    Date &PreviousYear();

    static bool IsLeapYear(int year);
    static bool IsValidDate(int _year, int _month, int _day);
    static int GetDayOfWeek(int year, int month, int day);
    static void PrintDayOfWeek(int year, int month, int day);
};
#endif