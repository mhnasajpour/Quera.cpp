#ifndef Contact__
#define Contact__

#include <iostream>
#include <map>
using namespace std;

class Contact
{
private:
    string name;
    multimap<string, string> phoneNumber;

public:
    Contact(string _name);

    void setName(string _name);
    string getName();

    void addPhoneNumber(string _type, string _phoneNum);
    bool deletePhoneNumber(string _type, string _phoneNum);
    bool editPhoneNumber(string _type, string _oldPhoneNum, string _newPhoneNum);
    void printPhoneNum();

    bool operator<(Contact &);
};

#endif