#include "Date.h"

int get_max_month(int year, int month)
{
    switch (month)
    {
    case 1: return 31;
    case 2:
        if (Date::IsLeapYear(year))
            return 29;
        return 28;
    case 3: return 31;
    case 4: return 30;
    case 5: return 31;
    case 6: return 30;
    case 7: return 31;
    case 8: return 31;
    case 9: return 30;
    case 10: return 31;
    case 11: return 30;
    case 12: return 31;
    default: return 0;
    }
}

const char *weekDays_pack(int year, int month, int day){
    switch (Date::GetDayOfWeek(year, month, day))
    {
    case 0: return("Sunday");
    case 1: return("Monday");
    case 2: return("Tuesday");
    case 3: return("Wednesday");
    case 4: return("Thursday");
    case 5: return("Friday");
    case 6: return("Saturday");
    default: return NULL;
    }
}

const char *month_pack(int month)
{
    switch (month)
    {
    case 1: return "Jan";
    case 2: return "Feb";
    case 3: return "Mar";
    case 4: return "Apr";
    case 5: return "May";
    case 6: return "Jun";
    case 7: return "Jul";
    case 8: return "Aug";
    case 9: return "Sep";
    case 10: return "Oct";
    case 11: return "Nov";
    case 12: return "Dec";
    default: return NULL;
    }
}

bool Date::IsLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    return false;
}

bool Date::IsValidDate(int _year, int _month, int _day)
{
    if (_year < 1973 || _year > 9999)
        return false;
    else if (_month < 1 || _month > 12)
        return false;
    else if (_day < 1 || _day > get_max_month(_year, _month))
        return false;
    return true;
}

int Date::GetDayOfWeek(int year, int month, int day)
{
    int allDay = 0;
    for (int i = 1973; i < year; i++)
    {
        if (Date::IsLeapYear(i))
            allDay += 2;
        else
            allDay++;
    }

    for (int i = 1; i < month; i++)
        allDay += (get_max_month(year, i) - 28);

    allDay += day;
    return (allDay % 7);
}

void Date::PrintDayOfWeek(int year, int month, int day)
{
    printf("%s, ", weekDays_pack(year, month, day));
    printf("%d ", day);
    printf("%s ", month_pack(month));
    printf("%d\n", year);
}

//**********************************************************************************************************
Date::Date(int _year, int _month, int _day)
{
    year = _year;
    month = _month;
    day = _day;
}

void Date::SetDate(int _year, int _month, int _day)
{
    if (IsValidDate(_year, _month, _day) == false)
        return;

    year = _year;
    month = _month;
    day = _day;
}

void Date::SetYear(int _year)
{
    if (IsValidDate(_year, month, day) == false)
    {
        cout << "Error: Invalid year (1993-9999)!" << endl;
        return;
    }

    else
        year = _year;
}

void Date::SetMonth(int _month)
{
    if (IsValidDate(year, _month, day) == false)
    {
        cout << "Error: Invalid month (1-12)!" << endl;
        return;
    }

    else
        month = _month;
}

void Date::SetDay(int _day)
{
    if (IsValidDate(year, month, _day) == false)
    {
        cout << "Error: Invalid day! your input is: " << _day << " but last day of month is : " << get_max_month(year, month) << endl;
        return;
    }

    else
        day = _day;
}

int Date::GetYear() const
{
    return year;
}

const char *Date::GetMonth() const
{
    return month_pack(month);
}

void Date::Print() const
{
    Date::PrintDayOfWeek(year, month, day);
}

Date &Date::NextDay()
{
    if (IsValidDate(year, month, day + 1))
    {
        day++;
        return (*this);
    }
    else if (IsValidDate(year, month + 1, 1))
    {
        day = 1;
        month++;
        return (*this);
    }
    else if (IsValidDate(year + 1, 1, 1))
    {
        day = 1;
        month = 1;
        year++;
        return (*this);
    }
    else
    {
        cout << "Error: Next day is out of range!" << endl;
        return (*this);
    }
}

Date &Date::PreviousDay()
{
    if (IsValidDate(year, month, day - 1))
    {
        day--;
        return (*this);
    }
    else if (IsValidDate(year, month - 1, get_max_month(year, month - 1)))
    {
        day = get_max_month(year, month - 1);
        month--;
        return (*this);
    }
    else if (IsValidDate(year - 1, 12, 31))
    {
        day = 31;
        month = 12;
        year--;
        return (*this);
    }
    else
    {
        cout << "Error: Previous day is out of range!" << endl;
        return (*this);
    }
}

Date &Date::NextMonth()
{
    if (month == 12 && IsValidDate(year + 1, 1, day))
    {
        month = 1;
        year++;
        return (*this);
    }
    else if (IsValidDate(year, month + 1, day))
    {
        month++;
        return (*this);
    }
    else if (IsValidDate(year, month + 1, get_max_month(year, month + 1)))
    {
        month++;
        day = get_max_month(year, month);
        return (*this);
    }
    else
    {
        cout << "Error: Next month is out of range!" << endl;
        return (*this);
    }
}

Date &Date::PreviousMonth()
{
    if (month == 1 && IsValidDate(year - 1, 12, day))
    {
        month = 12;
        year--;
        return (*this);
    }
    else if (IsValidDate(year, month - 1, day))
    {
        month--;
        return (*this);
    }
    else if (IsValidDate(year, month - 1, get_max_month(year, month - 1)))
    {
        month--;
        day = get_max_month(year, month);
        return (*this);
    }
    else
    {
        cout << "Error: Previous month is out of range!" << endl;
        return (*this);
    }
}

Date &Date::NextYear()
{
    if (month == 2 && day == 29)
    {
        year++;
        day--;
        return (*this);
    }
    else if (IsValidDate(year + 1, month, day))
    {
        year++;
        return (*this);
    }
    else
    {
        cout << "Error: Next year is out of range!" << endl;
        return (*this);
    }
}

Date &Date::PreviousYear()
{
    if (month == 2 && day == 29)
    {
        year--;
        day--;
        return (*this);
    }
    else if (year > 1973)
    {
        year--;
        return (*this);
    }
    else
    {
        cout << "Error: Previous year is out of range!" << endl;
        return (*this);
    }
}