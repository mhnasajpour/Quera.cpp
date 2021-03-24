#include"Chair.h"

char* Chair::get_date(){
    return dateChair.int_date();
}

Chair::Chair(){
    colorChair = new char [20];
    materialChair = new char [20];
}

void Chair::set_date(int _year, int _month, int _day){
    dateChair.setYear(_year);
    dateChair.setMonth(_month);
    dateChair.setDay(_day);
}

void Chair::set_mat(char* mat){
    materialChair = mat;
}

char* Chair::get_mat(){
    return materialChair;
}

void Chair::set_color(char* temp){
    colorChair = temp;
}

char* Chair::get_color(){
    return colorChair;
}

Chair::~Chair(){
    delete [] colorChair;
    delete [] materialChair;
}