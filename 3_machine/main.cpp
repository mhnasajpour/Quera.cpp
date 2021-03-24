#include<iostream>
#include"Car.h"
using namespace std;

int main(){
    printf("The number of cars is: ");
    int numberCars;
    scanf("%d", &numberCars);
    Car* car = new Car [numberCars];

    for (int i=0; i<numberCars; i++){
        char* color_temp = new char [20];
        scanf("%s", color_temp);
        car[i].set_color(color_temp);

        int num_tire, num_chair;
        scanf("%d %d", &num_tire, &num_chair);
        car[i].set_new(num_tire, num_chair);
        car[i].set_num(num_tire, num_chair);

        int x1, x2, x3;
        scanf("%d %d %d", &x1, &x2, &x3);
        car[i].set_date(x1, x2, x3);

        for(int j=0; j<num_tire; j++){
            car[i].set_tire(j);
        }

        for(int j=0; j<num_chair; j++){
            car[i].set_chair(j);
        }
    }

    for (int i=0; i<numberCars; i++){
        cout << "car number is: " << i+1 << endl;
        cout << car[i].get_color() << ' ';
        cout << car[i].get_date_str() << endl;
        cout << car[i].get_numTire() << endl;
        for(int j=0; j<car[i].get_numTire(); j++){
            cout << car[i].get_dateTire(j) << endl;
        }
        cout << car[i].get_numChair() << endl;
        for(int j=0; j<car[i].get_numChair(); j++){
            cout << car[i].get_materialChair(j) << ' ';
            cout << car[i].get_dateChair(j) << ' ';
            cout << car[i].get_colorChair(j) << endl;
        }
    }

    delete[] car;
}
