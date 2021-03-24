#include <iostream>
#include "geometry.h"
using namespace std;

int main(){
    Point a;
    Point b(3,4);
    Point c(2,5);

    c.print_coordinate();
    b.print_coordinate();

    cout<< a.get_x()<< endl; 
    a.set_xy(9,6);
    a.print_coordinate();

    cout<< b.size()<< endl;
    cout<< c.size()<< endl;

    b.set_y(7);
    cout<< b.get_y()<< endl;
}