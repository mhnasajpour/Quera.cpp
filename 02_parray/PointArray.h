#include"geometry.h"

class PointArray{
private:
    Point* pointer;
    int size;
    void resize(int newSize);
public:
    PointArray();
    PointArray(Point* _points, int _size);
    ~PointArray();
    void PushBack(const Point &p);
    void insert(const int position, const Point &p);
    void remove(const int pos);
    const int getSize() const;
    void clear();
    Point* get(const int position);
    const Point* get(const int position) const;
};