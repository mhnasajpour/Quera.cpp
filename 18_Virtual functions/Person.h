#ifndef __Person
#define __Person

#include <iostream>

class Person
{
protected:
    std::string name;
    int age;

public:
    void setName(std::string _name);
    void setAge(int _age);

    std::string getName();
    int getAge();

    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

#endif