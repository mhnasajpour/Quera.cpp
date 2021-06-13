#include "Database.h"
#include <iomanip>

Database::Database()
{
    ifstream file("Database");
    file.close();
}

void Database::AddRecord(Employee *emp)
{
    ofstream file("Database", ios::app);
    file << emp->ID << " " << emp->age << " " << emp->salary << " " << emp->name << endl;
    file.close();
}

void Database::ListRecord()
{
    ifstream file("Database");
    Employee emp;
    while (!file.eof())
    {
        file >> emp.ID >> emp.age >> emp.salary;
        file.ignore(1);
        if (file.eof())
            break;
        getline(file, emp.name);
        cout << emp.ID << ' ' << emp.name << ' ' << emp.salary << ' ' << emp.age << endl;
    }
    file.close();
}

void Database::searchRecord(int _ID)
{
    ifstream file("Database");
    int i;
    while (!file.eof())
    {
        file >> i;
        if (i == _ID)
        {
            Employee emp;
            file >> emp.age >> emp.salary;
            getline(file, emp.name);
            cout << _ID << emp.name << ' ' << emp.salary << ' ' << emp.age << endl;
            return;
        }
        file.ignore(200, '\n');
    }
}

void Database::ModifyRecord(int _ID, Employee emp)
{
    bool isExist = false;
    ifstream file("Database");
    ofstream fileEdit("EditedFile.txt");

    int i;
    while (!file.eof())
    {
        file >> i;
        if (file.eof())
            break;

        else if (i == _ID)
        {
            fileEdit << emp.ID << ' ' << emp.age << ' ' << emp.salary << ' ' << emp.name << endl;
            file.ignore(200, '\n');
            isExist = true;
        }

        else
        {
            Employee edit;
            file >> edit.age >> edit.salary;
            getline(file, edit.name);
            fileEdit << i << ' ' << edit.age << ' ' << edit.salary << edit.name << endl;
        }
    }

    fileEdit.close();
    remove("Database");
    rename("EditedFile.txt", "Database");

    if (isExist)
        cout << "You edited user successfully" << endl;
    else
        cout << "This user does not exist!" << endl;
}

void Database::DeleteRecord(int _ID)
{
    ifstream file("Database");
    ofstream fileEdit("EditedFile.txt");

    int i;
    while (!file.eof())
    {
        file >> i;
        if (file.eof())
            break;

        else if (i == _ID)
            file.ignore(200, '\n');

        else
        {
            Employee edit;
            file >> edit.age >> edit.salary;
            getline(file, edit.name);
            fileEdit << i << ' ' << edit.age << ' ' << edit.salary << edit.name << endl;
        }
    }

    fileEdit.close();
    remove("Database");
    rename("EditedFile.txt", "Database");
}

void Database::SaveRecord(string requiresFile)
{
    requiresFile += ".txt";
    ofstream refile(requiresFile);
    ifstream file("Database");

    Employee emp;

    refile.width(20);
    refile << left << "ID";
    refile.width(20);
    refile << left << "Name";
    refile.width(20);
    refile << left << "Salary";
    refile.width(20);
    refile << left << "Age" << endl;
    refile << setw(70) << setfill('=') << "=" << endl;

    while (!file.eof())
    {
        file >> emp.ID >> emp.age >> emp.salary;
        file.ignore(1);
        if (file.eof())
            break;
        getline(file, emp.name);

        refile << setw(20) << setfill(' ');
        refile << left << emp.ID;
        refile.width(20);
        refile << left << emp.name;
        refile.width(20);
        refile << left << emp.salary;
        refile.width(20);
        refile << left << emp.age << endl;
    }
    file.close();
    refile.close();
}