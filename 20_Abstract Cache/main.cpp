#include "InheritCache.h"
#include <iostream>
using namespace std;

int main()
{
    int cp, n;
    cin >> n >> cp;
    InheritCache obj(cp);

    for (int i = 0; i < n; i++)
    {
        string setget;
        cin >> setget;

        if (setget == "set")
        {
            int key, num;
            cin >> key >> num;
            obj.set(key, num);
        }

        if (setget == "get")
        {
            int key;
            cin >> key;
            cout << obj.get(key) << endl;
        }
    }
}