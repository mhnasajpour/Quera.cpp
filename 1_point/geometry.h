class Point {
private:
    int x,y;
public:
    Point();
    Point(int _x, int _y);

    int get_x();
    int get_y();
    void set_x(int);
    void set_y(int);
    void set_xy(int, int);
    float size();
    void print_coordinate();
};