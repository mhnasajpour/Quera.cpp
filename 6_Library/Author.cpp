#include "Author.h"
#include <string.h>

Author::Author(const char *_name, bool _gender, const char *_email)
{
    name = new char[50];
    email = new char[60];
    strcpy(name, _name);
    strcpy(email, _email);
    gender = _gender;
}

Author::Author()
{
    name = new char[50];
    email = new char[60];
}

Author::Author(const Author &q)
{
    name = new char[50];
    email = new char[60];
    strcpy(name, q.name);
    strcpy(email, q.email);
    gender = q.gender;
}

Author::~Author()
{
    delete[] name;
    delete[] email;
}

char *Author::getName()
{
    return name;
}

char Author::getGender()
{
    if (gender == true)
        return 'm';
    return 'f';
}

char *Author::getEmail()
{
    return email;
}