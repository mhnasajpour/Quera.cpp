#include "Contact.h"

Contact::Contact(string _name)
{
    name = _name;
}

void Contact::setName(string _name)
{
    name = _name;
}

string Contact::getName()
{
    return name;
}

void Contact::addPhoneNumber(string _type, string _phoneNum)
{
    phoneNumber.insert(pair<string, string>(_type, _phoneNum));
}

bool Contact::deletePhoneNumber(string _type, string _phoneNum)
{
    pair<multimap<string, string>::iterator, multimap<string, string>::iterator> range;
    range = phoneNumber.equal_range(_type);

    while (range.first != range.second)
    {
        if (range.first->first == _type && range.first->second == _phoneNum)
        {
            phoneNumber.erase(range.first);
            return true;
        }

        range.first++;
    }

    return false;
}

bool Contact::editPhoneNumber(string _type, string _oldPhoneNum, string _newPhoneNum)
{
    pair<multimap<string, string>::iterator, multimap<string, string>::iterator> range;
    range = phoneNumber.equal_range(_type);

    while (range.first != range.second)
    {
        if (range.first->first == _type && range.first->second == _oldPhoneNum)
        {
            range.first->second = _newPhoneNum;
            return true;
        }

        range.first++;
    }

    return false;
}

void Contact::printPhoneNum()
{
    multimap<string, string>::iterator it = phoneNumber.begin();
    while (it != phoneNumber.end())
    {
        cout << it->first << " => " << it->second << endl;
        it++;
    }
}

bool Contact::operator<(Contact &con)
{
    return (name < con.name);
}