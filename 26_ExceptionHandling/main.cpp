#include "DateTime.h"
#include <vector>

#define SIZE 5

int main()
{
    for (int i = 0; i < SIZE; i++)
    {
        int _hour, _minute;
        int _year, _month, _day;

        cin >> _day >> _month >> _year;
        cin >> _hour >> _minute;

        try
        {
            DateTime dt(_day, _month, _year, _hour, _minute);
            cout << dt.getDay() << ' ' << dt.getMonth() << ' ' << dt.getYear() << ' ' << dt.getHour() << ' ' << dt.getMinute() << endl;
        }
        catch (DateTimeException error)
        {
            cout << error.what() << " => " << error.getError() << endl;
        }
    }
}