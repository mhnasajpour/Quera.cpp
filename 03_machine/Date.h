#ifndef once
#define once

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Date{
private:
    int day, month, year;

public:
    char* int_date();
    char* str_date();
    void setDay(int);
    void setMonth(int);
    void setYear(int);
};

#endif