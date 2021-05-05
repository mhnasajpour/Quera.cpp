#ifndef __Employees
#define __Employees

#include <iostream>
using namespace std;

class Employee
{
private:
    string name;
    string socialNum;
    string employeeNum;

public:
    Employee();
    Employee(string name, string socialNum, string employeeNum);

    void setName(string _name);
    bool setSocialNum(string _socialNum);
    bool setEmployeeNum(string _employeeNum);

    string getName();
    string getSocialNum();
    string getEmployeeNum();
};

#endif