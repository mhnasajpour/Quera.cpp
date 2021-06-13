#ifndef Database__
#define Database__

#include <iostream>
#include <fstream>
using namespace std;

struct Employee
{
    int ID;
    int salary;
    int age;
    string name;
};

class Database
{
public:
    Database();
    void AddRecord(Employee *emp);
    void ListRecord();
    void ModifyRecord(int ID, Employee emp);
    void DeleteRecord(int ID);
    void searchRecord(int ID);
    void SaveRecord(string requiresFile);
};

#endif