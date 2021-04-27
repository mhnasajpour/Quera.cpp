#include "Library.h"
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
    for (int i = 0; i < sizeofBook; i++)
        temp[i] = this->book[i];
    delete[] book;
    book = new Book[newSize];
    book = temp;
}

void Library::addBook(Book *temp)
{
    if (spaceBook == sizeofBook)
        increaseSpaceBook(spaceBook + 100);

    for (int i = 0; i < sizeofBook; i++)
        if (strcmp(book[i].getName(), temp->getName()) == 0 && book[i].exist() == true)
        {
            book[i].setTotal();
            return;
        }

    book[sizeofBook++] = *temp;
}

char *Library::getName()
{
    return libName;
}

bool Library::isOpen(int time)
{
    if (time >= startTime && time <= endTime)
        return true;
    return false;
}

void Library::printBooks()
{
    Book *r = new Book;
    for (int i = 0; i < sizeofBook; i++)
    {
        for (int j = i; j < sizeofBook; j++)
        {
            if (strcmp(book[i].getName(), book[j].getName()) > 0)
            {
                *r = book[i];
                book[i] = book[j];
                book[j] = *r;
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
        if (strcmp(book[i].getAuthor().getName(), name) == 0)
            printf("%s %d\n", book[i].getName(), book[i].getPublishYear());
    }
}

bool Library::isExistBook(const char *_name)
{
    for (int i = 0; i < sizeofBook; i++)
    {
        if (strcmp(book[i].getName(), _name) == 0 && book[i].exist() == true)
            return true;
    }
    return false;
}

bool Library::lendBook(const char *_name)
{
    for (int i = 0; i < sizeofBook; i++)
    {
        if (strcmp(book[i].getName(), _name) == 0 && book[i].exist() == true)
        {
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
        if (strcmp(book[i].getName(), _name) == 0)
        {
            book[i].returnBook();
            return true;
        }
    }
    return false;
}
