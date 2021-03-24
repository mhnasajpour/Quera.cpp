#include"PointArray.h"
#include<iostream>
using namespace std;

PointArray::PointArray(){
    pointer = NULL;
    size = 0;
}

PointArray::PointArray(Point* _points, int _size){
    pointer = new Point [_size];
    for(int i=0; i<_size; i++){
        pointer[i] = _points[i];
    }
    size = _size;
}

PointArray::~PointArray(){
    delete[] pointer;
}

void PointArray::resize(int newSize){
    Point* temp = new Point [newSize];

    for(int i=0; i<size; i++){
        temp[i] = pointer[i];
    }

    delete[] pointer;
    pointer = new Point [newSize];

    for(int i=0; i<newSize; i++){
        pointer[i] = temp[i];
    }
    size = newSize;
}

void PointArray::PushBack(const Point &p){
    resize(size+1);
    pointer[size-1] = p;
}

void PointArray::insert(const int position, const Point &p){
    if(position > size){
        cout << "Error" << endl;
        return;
    }
    resize(1+size);
    for(int i=size; i>position; i--){
        pointer[i] = pointer[i-1];
    }
    pointer[position] = p;
}

void PointArray::remove(const int pos){
    if(pos >= size){
        cout << "Error" << endl;
        return;
    }
    for(int i=pos; i<size; i++){
        pointer[i] = pointer[i+1];
    }
    resize(size-1);
}

const int PointArray::getSize() const{
    return size;
}

void PointArray::clear(){
    delete[] pointer;
    pointer = NULL;
    size = 0;
}

Point* PointArray::get(const int position){
    if(position >= size){
        return NULL;
    }
    return (pointer+position);
}

const Point* PointArray::get(const int position) const{
    if(position >= size){
        return NULL;
    }
    return (pointer+position);
}