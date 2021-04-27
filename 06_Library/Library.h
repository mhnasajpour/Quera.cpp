#include "Book.h"
#include <iostream>
using namespace std;

class Library
{
private:
    char *libName;
    char *address;
    int startTime;
    int endTime;
    int foundYear;
    int staffNum;
    Book *book;
    int sizeofBook; // number of books this moment
    int spaceBook;  // maximum size for add book
    void increaseSpaceBook(int newSize);

public:
    Library(const char *libName, const char *address, int startTime, int endTime, int foundYear, int staffNum, Book *book = NULL, int sizeofBook = 0);
    Library(const Library &);
    ~Library();
    void addBook(Book *);
    char *getName();
    bool isOpen(int time);
    void printBooks();
    void printAuthorsBook(char *name);
    bool isExistBook(const char *name);
    bool returnBook(const char *name);
    bool lendBook(const char *name);
};
