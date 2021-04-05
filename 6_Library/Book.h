#include "Author.h"

class Book
{
private:
    char *nameBook;
    int publishYear;
    Author author;
    int numExist;            // exist
    int total;               // lend + exist

public:
    Book(const char *nameBook, int publishYear, Author author, int numBooks=1);
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

//******************************************************************************************************
#include <string.h>
Book::Book(const char *_nameBook, int _publishYear, Author _author, int numBooks) : author(_author)
{
    nameBook = new char[30];
    strcpy(nameBook, _nameBook);
    publishYear = _publishYear;
    total = numExist = numBooks;
}

Book::Book()
{
    nameBook = new char[30];
    total = numExist = 1;
}

Book::Book(const Book &q) : author(q.author)
{
    nameBook = new char[30];
    strcpy(nameBook, q.nameBook);
    publishYear = q.publishYear;
    total = q.total;
    numExist = q.numExist;
}

Book::~Book()
{
    delete[] nameBook;
}

char *Book::getName()
{
    return nameBook;
}

int Book::getPublishYear()
{
    return publishYear;
}

Author Book::getAuthor()
{
    return author;
}

void Book::setTotal()
{
    total++;
    numExist++;
}

void Book::w_author(char *_name, bool _gender, char *_email)
{
    author.name = _name;
    author.gender = _gender;
    author.email = _email;
}

bool Book::returnBook()
{
    if (total > numExist)
    {
        numExist++;
        return true;
    }
    return false;
}

bool Book::lendBook()
{
    if (numExist > 0)
    {
        numExist--;
        return true;
    }
    return false;
}

bool Book::exist()
{
    if (total > numExist)
        return true;
    return false;
}