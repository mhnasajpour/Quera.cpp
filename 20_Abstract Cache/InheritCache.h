#ifndef __InheritCache
#define __InheritCache

#include "Cache.h"

class InheritCache : Cache
{
private:
    int **data;

public:
    InheritCache(int _size);
    ~InheritCache();

    void set(int _key, int _num);
    int get(int _key);
};

#endif