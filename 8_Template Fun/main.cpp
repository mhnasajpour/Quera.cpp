#include <iostream>
#include <string.h>
using namespace std;

template <typename T> T getMax(T x, T y);
template <typename T, int SIZE> T getMax(T *arr);
template <typename T> void Swap(T &x, T &y);
template <typename T, int SIZE> int find(T *arr, T temp);
template <typename T, int SIZE> void sort(T *arr);
template <typename T, int SIZE> void sort(T *arr);
void sort(char *arr);
template <typename T, int SIZE> T *valArray(T set);
template <typename T> T add(T a, T b);
char *add(char *a, char *b);
template <typename T> void print(T a);
void print(double a);

int main()
{
    int intArr[8] = {5, 2, 6, 1, 7, 4, 3, 0};
    cout << getMax<int, 8>(intArr) << endl;
    char chArr[6] = "hasan";
    cout << getMax<char, 6>(chArr) << endl;
    cout << getMax(18.3, 5.86) << endl;
    //*********************************************
    int a = 5, b = 3;
    Swap(a, b);
    cout << a << ' ' << b << endl;
    //*********************************************
    cout << find<int, 8>(intArr, 3) << endl;
    cout << find<int, 8>(intArr, 10) << endl;
    //*********************************************
    sort<int, 8>(intArr);
    sort(chArr);
    for (int i = 0; i < 8; i++)
        cout << intArr[i] << ' ';
    cout << endl;
    cout << chArr << endl;
    //*********************************************
    float *f = valArray<float, 10>(1.87);
    for (int i = 0; i < 10; i++)
        cout << f[i] << ' ';
    cout << endl;
    //*********************************************
    cout << add(5, 6) << endl;
    cout << add(5.36, 6.49) << endl;
    cout << add((char *)"ali", (char *)"mohammad") << endl;
    //*********************************************
    print(6);
    print(765.123);
    print(12.5);
    print("tina");
}

template <typename T>
T getMax(T x, T y)
{
    return x >= y ? x : y;
}

template <typename T, int SIZE>
T getMax(T *arr)
{
    T max = arr[0];
    for (int i = 1; i < SIZE; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

template <typename T>
void Swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

template <typename T, int SIZE>
int find(T *arr, T temp)
{
    for (int i = 0; i < SIZE; i++)
        if (arr[i] == temp)
            return i;

    return -1;
}

template <typename T, int SIZE>
void sort(T *arr)
{
    for (int i = 0; i < SIZE - 1; i++)
        for (int j = i + 1; j < SIZE; j++)
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
}

void sort(char *arr)
{
    for (int i = 0; i < strlen(arr); i++)
        for (int j = i + 1; j < strlen(arr); j++)
            if (arr[i] < arr[j])
                swap(arr[i], arr[j]);
}

template <typename T, int SIZE>
T *valArray(T set)
{
    T *arr = new T[SIZE];
    for (int i = 0; i < SIZE; i++)
        arr[i] = set;

    return arr;
}

template <typename T>
T add(T a, T b)
{
    return (a + b);
}

char *add(char *a, char *b)
{
    char *result = new char[strlen(a) + strlen(b) + 1];
    strcpy(result, a);
    strcat(result, b);
    return result;
}

template <typename T>
void print(T a)
{
    cout << a << endl;
}

void print(double a)
{
    double temp = a;
    int num = 0;
    while (temp >= 10)
    {
        temp /= 10;
        num++;
    }
    cout << temp << "00"
         << "e+" << (num) << endl;
}