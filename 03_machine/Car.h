#include<iostream>
#include"Tire.h"
#include"Chair.h"
using namespace std;

class Car{
private:
    char* color;
    Chair* chair;
    int num_chair;
    Tire* tire;
    int num_tire;
    Date date;

public: 
    Car();
    void set_new(int, int);
    void set_num(int, int);

    void set_date(int, int, int);
    char* get_date_str();

    int get_numTire();
    int get_numChair();
    void set_chair(int);
    void set_tire(int);
    
    char* get_dateChair(int);
    char* get_materialChair(int);
    char* get_colorChair(int);
    char* get_dateTire(int);

    void set_color(char*);
    char* get_color();

    ~Car();
};