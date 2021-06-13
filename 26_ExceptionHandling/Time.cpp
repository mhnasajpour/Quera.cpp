#include "Time.h"

Time::Time(int _hour, int _minute)
{
    if (_hour < 0 || _hour > 23 || _minute < 0 || _minute > 59)
        throw TimeException(_hour, _minute);

    hour = _hour;
    minute = _minute;
}

void Time::setHour(int _hour)
{
    if (_hour < 0 || _hour > 23)
        throw TimeException(_hour, minute);
    
    hour = _hour;
}

void Time::setMinute(int _minute)
{
    if (_minute < 0 || _minute > 59)
        throw TimeException(hour, _minute);
    
    minute = _minute;
}

int Time::getHour()
{
    return hour;
}

int Time::getMinute()
{
    return minute;
}

TimeException::TimeException(int _hour, int _minute)
{
    hour = _hour;
    minute = _minute;

    if (hour < 0 || hour > 23)
        message = "Hour is out of range";

    else
        message = "Minute is out of range"; 
}

int TimeException::getHour()
{
    return hour;
}

int TimeException::getMinute()
{
    return minute;
}

string TimeException::what()
{
    return message;
}