#include <stdbool.h>

class Author
{
private:
    char *name;
    bool gender;
    char *email;

public:
    Author(const char *name, bool gender, const char *email);
    Author();
    Author(const Author &);
    ~Author();
    char *getName();
    char getGender();
    char *getEmail();
    friend class Book;
};
