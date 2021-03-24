#include"Date.h"

char* Date::int_date(){
    char* temp = (char*)malloc(11 * sizeof(char));
    sprintf(temp, "%d/%d/%d", year, month, day);
    return temp;
}

char* Date::str_date(){
    char* temp = (char*)malloc(11 * sizeof(char));
    char* smonth = (char*)malloc(12 * sizeof(char));

    switch (month){
        case 1:
        strcpy(smonth, "farvardin");
        break;
        case 2:
        strcpy(smonth, "ordibehesht");
        break;
        case 3:
        strcpy(smonth, "khordad");
        break;
        case 4:
        strcpy(smonth, "tir");
        break;
        case 5:
        strcpy(smonth, "mordad");
        break;
        case 6:
        strcpy(smonth, "shahrivar");
        break;
        case 7:
        strcpy(smonth, "mehr");
        break;
        case 8:
        strcpy(smonth, "aban");
        break;
        case 9:
        strcpy(smonth, "azar");
        break;
        case 10:
        strcpy(smonth, "dey");
        break;
        case 11:
        strcpy(smonth, "bahman");
        break;
        case 12:
        strcpy(smonth, "esfand");
        break;
    }

    sprintf(temp, "%d %s %d", year, smonth, day);
    free(smonth);
    return temp;
}

void Date::setDay(int _day){
    day = _day;
}

void Date::setMonth(int _month){
    month = _month;
}

void Date::setYear(int _year){
    year = _year;
}