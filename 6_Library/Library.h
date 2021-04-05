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
    Library(const char *libName, const char *address, int startTime, int endTime, int foundYear, int staffNum, Book *book=NULL, int sizeofBook=0);
    Library(const Library &);
    ~Library();
    void addBook(Book*);
    bool isOpen(int time);
    void printBooks();
    void printAuthorsBook(char *name);
    bool isExistBook(const char *name);
    bool returnBook(const char *name);
    bool lendBook(const char *name);
};


//******************************************************************************************************************************
#include <string.h>
Library::Library(const char *_libName, const char *_address, int _startTime, int _endTime, int _foundYear, int _staffNum, Book *_book, int _sizeofBook) : book(_book)
{
    libName = new char[40];
    address = new char[150];
    strcpy(libName, _libName);
    strcpy(address, _address);
    startTime = _startTime;
    endTime = _endTime;
    foundYear = _foundYear;
    staffNum = _staffNum;
    sizeofBook = _sizeofBook;
    spaceBook = _sizeofBook;
}

Library::Library(const Library &q) : book(q.book)
{
    libName = new char[40];
    address = new char[150];
    strcpy(libName, q.libName);
    strcpy(address, q.address);
    startTime = q.startTime;
    endTime = q.endTime;
    foundYear = q.foundYear;
    staffNum = q.staffNum;
    sizeofBook = q.sizeofBook;
    spaceBook = q.spaceBook;
}

Library::~Library()
{
    delete[] libName;
    delete[] address;
}

void Library::increaseSpaceBook(int newSize)
{
    spaceBook = newSize;
    Book *temp = new Book[newSize];
    if(sizeofBook > 0){
        for (int i = 0; i < sizeofBook; i++)
            temp[i] = this->book[i];
        delete[] book;
        book = new Book[newSize];
        book = temp;
    }
    else{
        book = new Book[newSize];
    }
}

void Library::addBook(Book* temp)
{
    if (spaceBook == sizeofBook)
        increaseSpaceBook(spaceBook + 100);

    if(sizeofBook > 0){
        for (int i = 0; i < sizeofBook; i++)
            if (strcmp(book[i].getName(), temp->getName()) == 0 && book[i].exist() == true)
            {
                book[i].setTotal();
                return;
            }
    }

    book[sizeofBook++] = *temp;
}

bool Library::isOpen(int time)
{
    if (time > startTime && time < endTime)
        return true;
    return false;
}

void Library::printBooks()
{
    Book r;
    for (int i = 0; i < sizeofBook; i++)
    {
        for (int j = i + 1; j < sizeofBook; j++)
        {
            if (strcmp(book[i].getName(), book[j].getName()) > 0)
            {
                r = book[i];
                book[i] = book[j];
                book[j] = r;
            }
        }
    }

    for (int i = 0; i < sizeofBook; i++)
        printf("%s %d %s (%c) at %s\n", book[i].getName(), book[i].getPublishYear(), book[i].getAuthor().getName(), book[i].getAuthor().getGender(), book[i].getAuthor().getEmail());
}

void Library::printAuthorsBook(char *name)
{
    for (int i = 0; i < sizeofBook; i++)
    {
        if (strcmp(book[i].getName(), name) == 0)
            printf("%s %d\n", name, book[i].getPublishYear());
    }
}

bool Library::isExistBook(const char *_name)
{
    for (int i = 0; i < sizeofBook; i++)
    {
        if (strcpy(book[i].getName(), _name) == 0 && book[i].exist() == true)
            return true;
    }
    return false;
}

bool Library::lendBook(const char *_name)
{
    for (int i = 0; i < sizeofBook; i++)
    {
        if (strcpy(book[i].getName(), _name) == 0 && book[i].exist() == true){
            book[i].lendBook();
            return true;
        }
    }
    return false;
}

bool Library::returnBook(const char *_name)
{
    for (int i = 0; i < sizeofBook; i++)
    {
        if (strcpy(book[i].getName(), _name) == 0){
            book[i].returnBook();
            return true;
        }
    }
    return false;
}