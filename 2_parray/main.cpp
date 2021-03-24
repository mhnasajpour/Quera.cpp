#include<iostream>
#include "PointArray.h"
using namespace std;

int main(){
    PointArray a;
    int n;
    cout << "1 : Add a point at the end of the array" << endl;
    cout << "2 : Insert a point of special index" << endl;
    cout << "3 : Remove a point of special index" << endl;
    cout << "4 : Print size the array" << endl;
    cout << "5 : Delete array" << endl;
    cout << "6 : Print array" << endl;
    cout << "7 : Exit" << endl;

    while(1){

        cin >> n;
        int x1,x2,index;
        switch (n){
        case 1:
            cout << "Input x,y : ";
            scanf("%d %d", &x1, &x2);
            a.PushBack(Point(x1,x2));
            break;
        
        case 2:
            cout << "Input x,y : ";
            scanf("%d %d", &x1, &x2);
            int index;
            cout << "index is: ";
            scanf("%d", &index);
            a.insert(index, Point(x1,x2));
            break;

        case 3:
            cout << "index is: ";
            scanf("%d", &index);
            a.remove(index);
            break;

        case 4:
            cout << "The number of points is " << a.getSize() << endl;
            break;

        case 5:
            cout << "Array deleted successfully" << endl;
            a.clear();
            break;
        
        case 6:
            for(int i = 0; i < a.getSize(); i++)
            (a.get(0))[i].print_coordinate();
            break;

        case 7:
            return 0;
        }
    }
}