#include "User.h"

int main()
{
    User user;
    string name, _name, type, oldPhoneNum, newPhoneNum;
    int num = 0;

    cout << "1 => Add contact\t2 => Remove contact\t3 => Edit contact" << endl;
    cout << "4 => Add phoneNumber\t5 => Remove phoneNumber\t6 => Edit phoneNumber" << endl;
    cout << "7 => Add favourite\t8 => Remove favourite\t9 => Change favourite order" << endl;
    cout << "10 => Show all contacts\t11 => Show all phoneNumbers\t12 => Show all favourites" << endl;
    cout << "13 => Search contact\t14 => Exit\n" << endl;

    while (num != 14)
    {
        cout << "\nINPUT: ";
        cin >> num;
        cout << endl;

        switch (num)
        {
        case 1:
            cout << "Name => ";
            cin >> name;
            user.addContact(name);
            break;

        case 2:
            cout << "Name => ";
            cin >> name;

            if (user.removeContact(name))
                cout << "Your contact removed successfully" << endl;
            else
                cout << "This contact does not exist" << endl;

            break;

        case 3:
            cout << "Old name => ";
            cin >> name;
            cout << "New name => ";
            cin >> _name;

            user.getContact(name).setName(_name);
            cout << "Your contact edited successfully" << endl;
            break;

        case 4:
            cout << "Name => ";
            cin >> name;
            cout << "Type => ";
            cin >> type;
            cout << "PhoneNumber => ";
            cin >> newPhoneNum;

            user.getContact(name).addPhoneNumber(type, newPhoneNum);
            break;

        case 5:
            cout << "Name => ";
            cin >> name;
            cout << "Type => ";
            cin >> type;
            cout << "PhoneNumber => ";
            cin >> newPhoneNum;

            user.getContact(name).deletePhoneNumber(type, newPhoneNum);
            break;

        case 6:
            cout << "Name => ";
            cin >> name;
            cout << "Type => ";
            cin >> type;
            cout << "Old phoneNum => ";
            cin >> oldPhoneNum;
            cout << "New phoneNum => ";
            cin >> newPhoneNum;

            if (user.getContact(name).editPhoneNumber(type, oldPhoneNum, newPhoneNum))
                cout << "Your contact edited successfully" << endl;
            else
                cout << "This contact does not exist" << endl;

            break;

        case 7:
            cout << "Name => ";
            cin >> name;

            if (user.addFavourite(name))
                cout << "Your contact added to favorite" << endl;
            else
                cout << "This contact does not exist" << endl;

            break;

        case 8:
            cout << "Name => ";
            cin >> name;

            if (user.removeFavourite(name))
                cout << "Your contact removed from favorite" << endl;
            else
                cout << "This contact does not exist" << endl;

            break;

        case 9:
            cout << "Name1 => ";
            cin >> name;
            cout << "Name2 => ";
            cin >> _name;

            user.swapFavourite(name, _name);
            break;

        case 10:
            user.showAllContacts();
            break;

        case 11:
            cout << "Name => ";
            cin >> name;
            user.getContact(name).printPhoneNum();
            break;

        case 12:
            user.showAllFavourite();
            break;

        case 13:
            cout << "string => ";
            cin >> name;
            user.searchContacts(name);
            break;

        case 14:
            exit(0);

        default:
            cout << "Your input is invalid" << endl;
        }
    }
}