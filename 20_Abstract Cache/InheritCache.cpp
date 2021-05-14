#include "InheritCache.h"

InheritCache::InheritCache(int _size)
{
    data = new int *[_size];
    for (int i = 0; i < _size; i++)
        data[i] = new int[2];

    cp = _size;
}

InheritCache::~InheritCache()
{
    delete[] data;
}

void InheritCache::set(int _key, int _num)
{
    for (int i = 0; i < cp; i++)
    {
        if (data[i][1] == _key)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                data[j + 1][0] = data[j][0];
                data[j + 1][1] = data[j][1];

                data[0][0] = _key;
                data[0][1] = _num;

                return;
            }
        }
    }

    for (int j = cp - 2; j >= 0; j--)
    {
        data[j + 1][0] = data[j][0];
        data[j + 1][1] = data[j][1];
    }

    data[0][0] = _key;
    data[0][1] = _num;
}

int ::InheritCache::get(int _key)
{
    for (int i = 0; i < cp; i++)
        if (data[i][0] == _key)
            return data[i][1];

    return -1;
}