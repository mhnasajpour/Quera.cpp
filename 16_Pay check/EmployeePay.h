#ifndef __EmployeePay
#define __EmployeePay

#include <iostream>
#include "Employee.h"
using namespace std;

class EmployeePay : public Employee
{
private:
    double yearPay;
    double weekPay;

public:
    EmployeePay(double _yearPay);
    EmployeePay(string _name, string _socialNum, string _employeeNum, double _yearPay);
    
    bool setYearPay(double _yearPay);

    double getYearPay();
    double getWeekPay();
};

#endif