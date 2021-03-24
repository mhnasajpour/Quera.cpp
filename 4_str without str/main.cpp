#include"String.h"
#include<iostream>
using namespace std;

int main(){
    cout << "Hello. We want to make a string\nInput a string: ";
    char* a = new char [1000];
    cin >> a;
    String mainStr(a);
    delete[] a;

    cout << "1 : Set a new string" << endl;
    cout << "2 : Print current string" << endl;
    cout << "3 : print size of string" << endl;
    cout << "4 : Print string from index1 to index2" << endl;
    cout << "5 : Stick a new string to main string" << endl;
    cout << "6 : Find a string on main string" << endl;
    cout << "7 : Are the two strings equal" << endl;
    cout << "8 : Exit\n\n";

    int n;
    while(1){
        cin >> n;
        if(n == 1){
            cout << "Input new string: ";
            char* a = new char [1000];
            cin >> a;
            mainStr.setStr(a);
            delete[] a;
        }
        else if(n == 2){
            cout << "The string is ==> " << mainStr.getStr() << endl;
        }
        else if(n == 3){
            cout << "The size of string is ==> " << mainStr.getSize() << endl;
        }
        else if(n == 4){
            int index1, index2;
            cout << "Index1: ";
            cin >> index1;
            cout << "Index2: ";
            cin >> index2;
            cout << "This token is ==> " << mainStr.subStr(index1, index2) << endl;
        }
        else if(n == 5){
            cout << "Input a string that you want to stick: ";
            char* a = new char [1000];
            cin >> a; 
            mainStr.append(a);
            delete[] a;
        }
        else if(n == 6){
            cout << "Input a string that you want to find: ";
            char* a = new char [1000];
            cin >> a; 
            cout << "The first index that has this string is: " << mainStr.findSubStr(a) << endl;
            delete[] a;
        }
        else if(n == 7){
            cout << "Input a string that you want to campare with main string: ";
            char* a = new char [1000];
            cin >> a; 

            if(mainStr.strCmp(a))
                cout << "this string is equal to main string" << endl;
            else
                cout << "this string is not equal to main string" << endl;   
                

            delete[] a;         
        }
        else if(n == 8){
            break;
        }
        else{
            cout << "Your input is wrong. please try again with right input" << endl;
        }
    }
}