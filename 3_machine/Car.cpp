#include"Car.h"

Car::Car(){
    color = new char [20];
}

void Car::set_new(int num_tire, int num_chair){
    tire = new Tire [num_tire];
    chair = new Chair [num_chair];
}

void Car::set_chair(int i){
    char* t_color = new char [20];
    char* t_mat = new char [20];
    scanf("%s %s", t_color, t_mat);
    this->chair[i].set_color(t_color);
    this->chair[i].set_mat(t_mat);
    int x1, x2, x3;
    scanf("%d %d %d", &x1, &x2, &x3);
    this->chair[i].set_date(x1, x2, x3);
}

void Car::set_tire(int i){
    int x1, x2, x3;
    scanf("%d %d %d", &x1, &x2, &x3);
    this->tire[i].set_date(x1, x2, x3);
}

char* Car::get_dateChair(int i){
    return this->chair[i].get_date();
}

char* Car::get_dateTire(int i){
    return this->tire[i].get_date();
}

char* Car::get_materialChair(int i){
    return chair[i].get_mat();
}

char* Car::get_colorChair(int i){
    return chair[i].get_color();
}

void Car::set_color(char* _color){
    color = _color;
}

char* Car::get_color(){
    return color;
}

void Car::set_date(int x1, int x2, int x3){
    date.setYear(x1);
    date.setMonth(x2);
    date.setDay(x3);
}


char* Car::get_date_str(){
    return date.str_date();
}

void Car::set_num(int t, int ch){
    num_chair = ch;
    num_tire = t;
}

int Car::get_numChair(){
    return num_chair;
}

int Car::get_numTire(){
    return num_tire;
}

Car::~Car(){
    delete [] color;
    delete [] chair;
    delete [] tire;
}