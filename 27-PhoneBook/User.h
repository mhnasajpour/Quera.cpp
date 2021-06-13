#ifndef User__
#define User__

#include "Contact.h"
#include <list>
#include <vector>

class User
{
private:
    list<Contact> contacts;
    vector<Contact> favourite;

public:
    void addContact(string _name);   
    bool removeContact(string _name);
    Contact &getContact(string _name);
    void showContactPhoneNum(string _name);
    void showAllContacts();
    void searchContacts(string str);

    bool addFavourite(string _name);
    bool removeFavourite(string _name);
    void showAllFavourite();
    void swapFavourite(string _name1, string _name2);
};

#endif