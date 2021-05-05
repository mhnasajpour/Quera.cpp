#include "EmployeePay.h"

EmployeePay::EmployeePay(double _yearPay)
{
    setYearPay(_yearPay);
}

EmployeePay::EmployeePay(string _name, string _socialNum, string _employeeNum, double _yearPay) : Employee(_name, _socialNum, _employeeNum)
{
    setYearPay(_yearPay);
}

bool EmployeePay::setYearPay(double _yearPay)
{
    if (_yearPay < 0)
        return false;

    yearPay = _yearPay;
    weekPay = (yearPay / 365) * 7;
    return true;
}

double EmployeePay::getYearPay()
{
    return yearPay;
}

double EmployeePay::getWeekPay()
{
    return weekPay;
}