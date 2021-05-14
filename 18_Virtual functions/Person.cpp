#include "Person.h"

void Person::setName(std::string _name)
{
    name = _name;
}

void Person::setAge(int _age)
{
    age = _age;
}

std::string Person::getName()
{
    return name;
}

int Person::getAge()
{
    return age;
}