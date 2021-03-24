#include"String.h"
#include<stdbool.h>

int strlen(char* temp){
    int i=0;
    while(temp[i] != '\0'){
        i++;
    }
    return i;
}

void strcpy(char* a, char* b){
    for(int i=0; i <= strlen(b); i++){
        a[i] = b[i];
    }
}

void strcat(char* a, char* b){
    for(int i=0; i <= strlen(b); i++){
        a[strlen(a)] = b[i];
    }
}

String::String(){
    str = new char[5];
    strcpy(str, (char*)"");
    setSize(0);
}

String::String(char* _a){
    str = new char[strlen(_a)+1];
    strcpy(str, _a);
    setSize(strlen(_a));
}

String::String(char* _a, int _size){
    str = new char[size+1];
    strcpy(str, _a);
    setSize(_size);
}

String::~String(){
    delete[] str;
}

void String::setStr(char* _a){
    this-> ~String();
    str = new char[strlen(_a)+1];
    strcpy(str, _a);
    setSize(strlen(_a));
}

char* String::getStr(){
    return str;
}

void String::setSize(int a){
    size = a;
}

int String::getSize(){
    return size;
}

char* String::subStr(int index1, int index2){
    char* temp = new char [index2-index1+2];
    int j=0;
    for(int i=index1; i<=index2; i++){
        temp[j] = str[i];
        j++;
    }
    temp[j] = '\0';
    return temp;
}

void String::append(char* temp){
    char* new_str = new char [size + strlen(temp)+1];
    strcpy(new_str, str);
    strcat(new_str, temp);
    delete[] str;
    str = new char [size + strlen(temp) + 1];
    strcpy(str, new_str);
    delete[] new_str;
    setSize(strlen(str));
}

int String::findSubStr(char* temp){
    if(size<strlen(temp)){
        return -1;
    }

    for(int i=0; i<=size-strlen(temp); i++){
        int q=0;
        for(int j=0; j<strlen(temp); j++){
            if(str[i+j] != temp[j]){
                break;
            }
            q++;
        }
        if(q == strlen(temp)){
            return i;
        }
    }
    return -1;
}

bool String::strCmp(char* temp){
    if(size != strlen(temp)){
        return false;
    }

    for(int i=0; i<size; i++){
        if(temp[i] != str[i]){
            return false;
        }
    }

    return true;
}