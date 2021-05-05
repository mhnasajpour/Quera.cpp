#ifndef __HourlyPay
#define __HourlyPay

#include <iostream>
#include "EmployeePay.h"
using namespace std;

class HourlyPay : public EmployeePay
{
private:
    int hoursWorkPerWeek;
    double payPerHour;
    void setPayPerHours();

public:
    HourlyPay(double _yearPay = 0, int _hoursWorkPerWeek = 0);
    HourlyPay(string _name, string _socialNum, string _employeeNum, double _yearPay, int _hoursWorkPerWeek);

    bool sethoursWork(int _hoursWorkPerWeek);

    int getHoursWork();
    double getPayPerHour();

    double getWorkOverTime();

    double processSalary();
};

#endif