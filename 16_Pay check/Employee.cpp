#include "Employee.h"

Employee::Employee() {}

Employee::Employee(string _name, string _socialNum, string _employeeNum)
{
    setName(_name);
    setSocialNum(_socialNum);
    setEmployeeNum(_employeeNum);
}

void Employee::setName(string _name)
{
    name = _name;
}

bool Employee::setSocialNum(string _socialNum)
{
    if(_socialNum.size() != 10)
        return false;

    for (int i = 0; i < 10; i++)
        if ((i == 3 || i == 6) && _socialNum[i] != '-')
            return false;
        else if ((i != 3 && i != 6) && (_socialNum[i] < '0' || _socialNum[i] > '9'))
            return false;

    socialNum = _socialNum;
    return true;
}

bool Employee::setEmployeeNum(string _employeeNum)
{
    if(_employeeNum.size() != 5)
        return false;

    for (int i = 0; i < 3; i++)
        if (_employeeNum[i] < '0' || _employeeNum[i] > '9')
            return false;

    if (_employeeNum[3] != '-')
        return false;

    if (_employeeNum[4] < 'A' || _employeeNum[4] > 'M')
        return false;

    employeeNum = _employeeNum;
    return true;
}

string Employee::getName()
{
    return name;
}

string Employee::getSocialNum()
{
    return socialNum;
}

string Employee::getEmployeeNum()
{
    return employeeNum;
}