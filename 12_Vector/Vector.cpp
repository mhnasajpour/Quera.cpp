#include "Vector.h"
#include <iostream>
using namespace std;

template <class T>
Vector<T>::Vector()
{
    dataSize = 0;
    dataStruct = new T[dataSize];
}

template <class T>
Vector<T>::Vector(const Vector &p)
{
    dataSize = p.dataSize;
    dataStruct = new T[dataSize];
    for (int i = 0; i < dataSize; i++)
        dataStruct[i] = p.dataStruct[i];
}

template <class T>
Vector<T>::~Vector()
{
    delete[] dataStruct;
}

//**************************************************************************
template <class T>
void Vector<T>::push_back(T data)
{
    T *temp = new T[dataSize + 1];
    for (int i = 0; i < dataSize; i++)
        temp[i] = dataStruct[i];

    delete[] dataStruct;
    dataStruct = temp;

    dataStruct[dataSize] = data;
    dataSize++;
}

template <class T>
void Vector<T>::push_front(T data)
{
    T *temp = new T[++dataSize];
    for (int i = 0; i < dataSize - 1; i++)
        temp[i + 1] = dataStruct[i];

    delete[] dataStruct;
    dataStruct = temp;

    dataStruct[0] = data;
}

template <class T>
void Vector<T>::insert(int index, T data)
{
    if (index >= dataSize)
        return;
    dataStruct[index] = data;
}

template <class T>
void Vector<T>::pop()
{
    if (dataSize == 0)
        return;

    T *temp = new T[--dataSize];
    for (int i = 0; i < dataSize; i++)
        temp[i] = dataStruct[i];

    delete[] dataStruct;
    dataStruct = temp;
}

template <class T>
void Vector<T>::Delete(int index)
{
    if (index >= dataSize)
        return;

    T *temp = new T[dataSize - 1];
    int j = 0;
    for (int i = 0; i < dataSize; i++)
    {
        if (i == index)
            i++;
        temp[j] = dataStruct[i];
        j++;
    }

    delete[] dataStruct;
    dataStruct = temp;
    dataSize--;
}

template <class T>
int Vector<T>::search(T data)
{
    for (int i = 0; i < dataSize; i++)
        if (dataStruct[i] == data)
            return i;

    return -1;
}

template <class T>
int Vector<T>::size()
{
    return dataSize;
}

template <class T>
void Vector<T>::swap(int index1, int index2)
{
    if (index1 >= dataSize || index2 >= dataSize)
        return;

    T temp = dataStruct[index1];
    dataStruct[index1] = dataStruct[index2];
    dataStruct[index2] = temp;
}

template <class T>
void Vector<T>::reverse()
{
    for (int i = 0; i < dataSize / 2; i++)
        swap(i, dataSize - 1 - i);
}

template <class T>
void Vector<T>::sort()
{
    for (int i = 0; i < dataSize - 1; i++)
        for (int j = i + 1; j < dataSize; j++)
            if (dataStruct[i] > dataStruct[j])
                swap(i, j);
}

//**************************************************************************
template <typename T>
ostream &operator<<(ostream &out, Vector<T> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        out << vec.dataStruct[i] << ' ';

    return out;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T> &vec)
{
    if ((vec.dataStruct == nullptr) && (dataStruct == nullptr))
        return true;
    else if (dataSize != vec.dataSize)
        return false;

    for (int i = 0; i < vec.dataSize; i++)
        if (dataStruct[i] != vec.dataStruct[i])
            return false;

    return true;
}

template <class T>
Vector<T> &Vector<T>::operator=(const Vector &p)
{
    dataSize = p.dataSize;
    dataStruct = new T[dataSize];
    for (int i = 0; i < dataSize; i++)
        dataStruct[i] = p.dataStruct[i];

    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &q)
{
    Vector<T> temp;
    temp.dataSize = q.dataSize + this->dataSize;

    temp.dataStruct = new T[temp.dataSize];
    for (int i = 0; i < this->dataSize; i++)
        temp.dataStruct[i] = this->dataStruct[i];

    for (int i = this->dataSize; i < q.dataSize + this->dataSize; i++)
        temp.dataStruct[i] = q.dataStruct[i - this->dataSize];

    return temp;
}

template <typename T>
Vector<T> Vector<T>::operator+(const T &data)
{
    Vector temp = *this;
    temp.push_back(data);
    return temp;
}

template <typename T>
Vector<T> &Vector<T>::operator+=(const Vector<T> &q)
{
    for (int i = 0; i < q.dataSize; i++)
        this->push_back(q.dataStruct[i]);
    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator+=(const T &data)
{
    this->push_back(data);
    return *this;
}

template <typename T>
T &Vector<T>::operator[](const int &index)
{
    return dataStruct[index];
}
