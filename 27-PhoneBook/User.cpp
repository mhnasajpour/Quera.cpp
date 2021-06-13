#include "User.h"

void User::addContact(string _name)
{
    contacts.push_back(_name);
}

bool User::removeContact(string _name)
{
    list<Contact>::iterator it = contacts.begin();

    while (it != contacts.end())
    {
        if (it->getName() == _name)
        {
            contacts.erase(it);
            return true;
        }

        it++;
    }

    return false;
}

Contact &User::getContact(string _name)
{
    list<Contact>::iterator it = contacts.begin();

    while (it != contacts.end())
    {
        if (it->getName() == _name)
            return *it;

        it++;
    }
    return *it;
}

void User::showContactPhoneNum(string _name)
{
    Contact c = getContact(_name);
    c.printPhoneNum();
}

void User::showAllContacts()
{
    contacts.sort();
    list<Contact>::iterator it = contacts.begin();

    while (it != contacts.end())
    {
        cout << it->getName() << endl;
        it++;
    }
}

void User::searchContacts(string str)
{
    list<Contact>::iterator it = contacts.begin();
    while (it != contacts.end())
    {
        if (it->getName().find(str) != string::npos)
            cout << it->getName() << endl;
        it++;
    }
}

bool User::addFavourite(string _name)
{
    list<Contact>::iterator it = contacts.begin();
    while (it != contacts.end())
    {
        if (it->getName() == _name)
        {
            favourite.push_back(*it);
            return true;
        }

        it++;
    }

    return false;
}

bool User::removeFavourite(string _name)
{
    vector<Contact>::iterator it = favourite.begin();
    while (it != favourite.end())
    {
        if (it->getName() == _name)
        {
            favourite.erase(it);
            return true;
        }

        it++;
    }

    return false;
}

void User::showAllFavourite()
{
    vector<Contact>::iterator it = favourite.begin();
    while (it != favourite.end())
    {
        cout << it->getName() << endl;
        it->printPhoneNum();
        it++;
    }
}

void User::swapFavourite(string _name1, string _name2)
{
    vector<Contact>::iterator it1 = favourite.begin(), it2 = favourite.begin();
    while (it1 != favourite.end())
    {
        if (it1->getName() == _name1)
            break;

        it1++;
    }

    while (it2 != favourite.end())
    {
        if (it2->getName() == _name2)
            break;

        it2++;
    }

    swap(it1, it2);
}