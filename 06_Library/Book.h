#include "Author.h"

class Book
{
private:
    char *nameBook;
    int publishYear;
    Author author;
    int numExist; // exist
    int total;    // lend + exist

public:
    Book(const char *nameBook, int publishYear, Author author, int numBooks = 1);
    Book();
    Book(const Book &);
    ~Book();
    char *getName();
    int getPublishYear();
    Author getAuthor();
    void setTotal();
    void w_author(char *name, bool gender, char *email);
    bool returnBook();
    bool lendBook();
    bool exist();
};
