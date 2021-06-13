#include "Database.h"

int main()
{
    Database data;
    Employee emp;
    int num = 0, _ID;
    string requiresFile;

    cout << "1 => Add Record\n2 => List Record\n3 => Modify Record\n4 => Delete Record\n5 => Search Record\n6 => Save Record\n7 => Exit\n" << endl;

    while (num != 7)
    {
        cout << "\nINPUT: ";
        cin >> num;
        switch (num)
        {
        case 1:
            cout << "ID => ";
            cin >> emp.ID;
            cin.ignore(1);
            cout << "Name => ";
            getline(cin, emp.name);
            cout << "Age => ";
            cin >> emp.age;
            cout << "Salary => ";
            cin >> emp.salary;
            data.AddRecord(&emp);
            break;

        case 2:
            data.ListRecord();
            break;

        case 3:
            cout << "IDRequest => ";
            cin >> _ID;
            cout << "ID => ";
            cin >> emp.ID;
            cin.ignore(1);
            cout << "Name => ";
            getline(cin, emp.name);
            cout << "Age => ";
            cin >> emp.age;
            cout << "Salary => ";
            cin >> emp.salary;
            data.ModifyRecord(_ID, emp);
            break;

        case 4:
            cout << "IDRequest => ";
            cin >> _ID;
            data.DeleteRecord(_ID);
            break;

        case 5:
            cout << "IDRequest => ";
            cin >> _ID;
            data.searchRecord(_ID);
            break;

        case 6:
            cout << "fileName => ";
            cin >> requiresFile;
            data.SaveRecord(requiresFile);
            break;

        case 7:
            exit(0);

        default:
            cout << "Your input is invalid" << endl;
        }
    }
}
