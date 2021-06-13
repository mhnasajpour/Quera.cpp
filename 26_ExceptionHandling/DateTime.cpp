#include "DateTime.h"

DateTime::DateTime(int _day, int _month, int _year, int _hour, int _minute)
{
    try{
        setDay(_day);
    }
    catch(int error)
    {
        if(error < 1)
            setDay(1);
        
        else
            setDay(31);
    }
    
    try{
        setMinute(_minute);
    }
    catch(TimeException error){
        if(error.getMinute() < 0)
            setMinute(0);
        else 
            setMinute(59);
    }

    try{
        setYear(_year);
    }
    catch(DateException error){
        throw DateTimeException(_year, "Year is invalid");
    }

    try{
        setHour(_hour);
    }
    catch(TimeException error){
        throw DateTimeException(_hour, "Hour is invalid");
    }

    setMonth(_month);
}

DateTimeException::DateTimeException(int _error, string _message)
{
    error = _error;
    message = _message;
}

int DateTimeException::getError()
{
    return error;
}

string DateTimeException::what()
{
    return message;
}