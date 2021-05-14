#ifndef __Student
#define __Student

#include "Person.h"

class Student : public Person
{
private:
    int curId;
    int mark[6];
    static int setId;

public:
    Student();
    void getdata();
    void putdata();
};

#endif