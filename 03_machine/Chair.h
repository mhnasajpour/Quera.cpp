#include"Date.h"

class Chair{
private:
    char* colorChair;
    char* materialChair;
    Date dateChair;
    
public:
    Chair();
    void set_date(int, int, int);
    char* get_date();
    void set_mat(char*);
    char* get_mat();
    void set_color(char*);
    char* get_color();
    ~Chair();
};