#include "HourlyPay.h"

HourlyPay::HourlyPay(double _yearPay, int _hoursWorkPerWeek) : EmployeePay(_yearPay)
{
    sethoursWork(_hoursWorkPerWeek);
    setPayPerHours();
}

HourlyPay::HourlyPay(string _name, string _socialNum, string _employeeNum, double _yearPay, int _hoursWorkPerWeek) : EmployeePay(_name, _socialNum, _employeeNum, _yearPay)
{
    sethoursWork(_hoursWorkPerWeek);
    setPayPerHours();
}

void HourlyPay::setPayPerHours()
{
    payPerHour = getWeekPay() / 40;
}

bool HourlyPay::sethoursWork(int _hoursWorkPerWeek)
{
    if (_hoursWorkPerWeek < 0 || _hoursWorkPerWeek > 60)
        return false;

    hoursWorkPerWeek = _hoursWorkPerWeek;
    return true;
}

int HourlyPay::getHoursWork()
{
    return hoursWorkPerWeek;
}

double HourlyPay::getPayPerHour()
{
    setPayPerHours();
    return payPerHour;
}

double HourlyPay::getWorkOverTime()
{
    if (hoursWorkPerWeek <= 40)
        return 0;

    return ((hoursWorkPerWeek - 40) * (1.5 * payPerHour));
}

double HourlyPay::processSalary()
{
    setPayPerHours();

    if (hoursWorkPerWeek <= 40)
        return getWeekPay() + (payPerHour) * (hoursWorkPerWeek - 40);

    return getWeekPay() + ((payPerHour * 1.5) * (hoursWorkPerWeek - 40));
}