#include "geometry.h"
#include <stdio.h>
#include <math.h>

Point::Point(){
    x = 0;
    y = 0;
}

Point::Point(int _x, int _y){
    x = _x;
    y = _y;
}

int Point::get_x(){
    return x;
}

int Point::get_y(){
    return y;
}

void Point::set_x(int _x){
    x = _x;
}

void Point::set_y(int _y){
    y = _y;
}

void Point::set_xy(int _x, int _y){
    x = _x;
    y = _y;
}

float Point::size(){
    return sqrt((x*x) + (y*y));
}

void Point::print_coordinate(){
    printf("(%d,%d)\n", x, y);
}