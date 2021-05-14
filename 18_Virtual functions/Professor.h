#ifndef __Professor
#define __Professor

#include "Person.h"

class Professor : public Person
{
private:
    int curId;
    int publications;
    static int setId;

public:
    Professor();
    void getdata();
    void putdata();
};

#endif