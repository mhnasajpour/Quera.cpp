#include "Fractional.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a1, a2, b1, b2, num;
    char c;
    cin >> a1 >> c >> a2 >> b1 >> c >> b2;

    Fractional class1(a1, a2);
    Fractional class2(b1, b2);
    Fractional result(0,0);

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        string input;
        cin >> input;
        
        if (input == "+"){
            result = class1 + class2;
            cout << result << endl;
        }

        else if (input == "-"){
            result = class1 - class2;
            cout << result << endl;
        }

        else if (input == "*"){
            result = class1 *class2;
            cout << result << endl;
        }

        else if (input == "/"){
            result = class1 / class2;
            cout << result << endl;
        }

        else if (input == "=="){
            int s = class1 == class2;
            cout << s << endl;
        }

        else if (input == "+="){
            class1 += class2;
            cout << class1 << endl;
        }

        else if (input == ">"){
            int s = class1 > class2;
            cout << s << endl;
        }

        else {
            int s = (input[0] == '1') ? class1[input[2]-48] : class2[input[2]-48];
            cout << s << endl;
        }
        
    }
}