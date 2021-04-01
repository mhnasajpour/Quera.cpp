#include <iostream>
#include <stdbool.h>
#include <string.h>
using namespace std;

#define SIZE 10
#define RES 25

char *fun(char *str1, char *str2);
char *fun(char *str1, int a);
char *fun(int a, char *str1);
char *fun(char *str1, float a);
char *fun(float a, char *str1);
template <typename T> T *fun(T *array1, T *array2, int size1, int size2);
template <typename T> T *fun(T one, T *array, int size_array);
template <typename T> T *fun(T *array, T one, int size_array);
int fun(int a, int b);
double fun(double a, double b);
double fun(int a, double b);
double fun(double a, int b);
bool fun(bool b1, bool b2);


int main()
{
    char str1[20] = "ali";
    char str2[20] = "mohammad";
    int num = 85;
    float f = 12.875;
    int a1[5] = {1, 2, 3, 4, 5};
    int a2[5] = {6, 7, 8, 9, 10};
    float b1[5] = {1.32, 2.51, 3.62, 4.74, 5.14};
    float b2[5] = {6.32, 7.51, 8.62, 9.74, 10.14};
    bool bool1 = true, bool2 = true, bool3 = false, bool4 = false;

    cout << "concat two strings:  " << fun(str1, str2) << endl;
    cout << "concat two strings:  " << fun(str2, str1) << endl;

    cout << "add a int to a string:  " << fun(num, str1) << endl;
    cout << "add a int to a string:  " << fun(str1, num) << endl;

    cout << "add a float to a string:  " << fun(f, str1) << endl;
    cout << "add a float to a string:  " << fun(str1, f) << endl;
    //**********************************
    int *s = fun(a1, a2, 5, 5);
    cout << "add two ints arrays:  ";
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", s[i]);
        if (i == 9)
            printf("\n");
    }

    s = fun(a2, a1, 5, 5);
    cout << "add two ints arrays:  ";
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", s[i]);
        if (i == 9)
            printf("\n");
    }
    //**********************************
    float *z = fun(b1, b2, 5, 5);
    cout << "add two floats arrays:  ";
    for (int i = 0; i < 10; i++)
    {
        printf("%.2f ", z[i]);
        if (i == 9)
            printf("\n");
    }

    z = fun(b2, b1, 5, 5);
    cout << "add two floats arrays:  ";
    for (int i = 0; i < 10; i++)
    {
        printf("%.2f ", z[i]);
        if (i == 9)
            printf("\n");
    }
    //********************************
    s = fun(0, a1, 5);
    cout << "add a int(0) to array:  ";
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", s[i]);
        if (i == 5)
            printf("\n");
    }

    s = fun(a1, 0, 5);
    cout << "add a int(0) to array:  ";
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", s[i]);
        if (i == 5)
            printf("\n");
    }

    z = fun((float)4.34, b1, 5);
    cout << "add a float(4.75) to array:  ";
    for (int i = 0; i < 6; i++)
    {
        printf("%.2f ", z[i]);
        if (i == 5)
            printf("\n");
    }

    z = fun(b1, (float)4.34, 5);
    cout << "add a float(4.75) to array:  ";
    for (int i = 0; i < 6; i++)
    {
        printf("%.2f ", z[i]);
        if (i == 5)
            printf("\n");
    }

    char *p = fun('*', str2, 8);
    cout << "add a char to array(str):  ";
    printf("%s\n", p);
    //********************************
    cout << "and two boolean(TT):  " << fun(bool1, bool2) << endl;
    cout << "and two boolean(FF):  " << fun(bool3, bool4) << endl;
    cout << "and two boolean(TF):  " << fun(bool1, bool3) << endl;
    //********************************
    cout << "plus tow num:  " << fun(4, 5) << endl;
    cout << "plus tow num:  " << fun(2.5, 9.7) << endl;
    cout << "plus tow num:  " << fun(1.9, 5) << endl;
    cout << "plus tow num:  " << fun(6, 5.3) << endl;
}

//===================================================>
char *fun(char *str1, char *str2)
{
    char *result = new char[RES];
    strcat(result, str1);
    strcat(result, str2);
    return result;
}
//****************************************************
char *fun(char *str1, int a)
{
    char *result = new char[RES];
    char convert[SIZE];
    sprintf(convert, "%d", a);
    strcat(result, str1);
    strcat(result, convert);
    return result;
}

char *fun(int a, char *str1)
{
    char *result = new char[RES];
    char convert[SIZE];
    sprintf(convert, "%d", a);
    strcat(result, convert);
    strcat(result, str1);
    return result;
}
//****************************************************
char *fun(char *str1, float a)
{
    char *result = new char[RES];
    char convert[SIZE];
    sprintf(convert, "%lf", a);
    strcat(result, str1);
    strcat(result, convert);
    return result;
}

char *fun(float a, char *str1)
{
    char *result = new char[RES];
    char convert[SIZE];
    sprintf(convert, "%lf", a);
    strcat(result, convert);
    strcat(result, str1);
    return result;
}
//===================================================>
template <typename T>
T *fun(T *array1, T *array2, int size1, int size2)
{
    T *res_arr = new T[size1 + size2];

    for (int i = 0; i < size1; i++)
        res_arr[i] = array1[i];

    for (int i = size1; i < size1 + size2; i++)
        res_arr[i] = array2[i - size1];

    return res_arr;
}
//****************************************************
template <typename T>
T *fun(T one, T *array, int size_array)
{
    T *res_arr = new T[size_array + 1];

    res_arr[0] = one;

    for (int i = 1; i < size_array + 1; i++)
        res_arr[i] = array[i - 1];

    return res_arr;
}

template <typename T>
T *fun(T *array, T one, int size_array)
{
    T *res_arr = new T[size_array + 1];

    for (int i = 0; i < size_array + 1; i++)
        res_arr[i] = array[i];

    res_arr[size_array] = one;

    return res_arr;
}
//===================================================>
bool fun(bool b1, bool b2)
{
    return (b1 & b2);
}
//===================================================>
int fun(int a, int b)
{
    return (a + b);
}

double fun(double a, double b)
{
    return (a + b);
}
//****************************************************
double fun(int a, double b)
{
    return (a + b);
}

double fun(double a, int b)
{
    return (a + b);
}
//===================================================>