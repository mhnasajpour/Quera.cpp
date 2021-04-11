#include <iostream>
#ifndef once
#define once
using namespace std;

template <class T>
class Vector
{
private:
    T *dataStruct = NULL; // An array
    int dataSize;         // Length of dataStruct

public:
    Vector();
    Vector(const Vector &);
    ~Vector();
    void push_back(T data);
    void push_front(T data);
    void insert(int index, T data);
    void pop();
    void Delete(int index);
    int search(T data);
    int size();
    void swap(int index1, int index2);
    void reverse();
    void sort();
    template <typename G>
    friend ostream &operator<<(ostream &out, Vector<G> &q);
};
#endif