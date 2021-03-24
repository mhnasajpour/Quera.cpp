#include"Tire.h"

void Tire::set_date(int _year, int _month, int _day){
    date_tire.setYear(_year);
    date_tire.setMonth(_month);
    date_tire.setDay(_day);
}

char* Tire::get_date(){
    return date_tire.int_date();
}