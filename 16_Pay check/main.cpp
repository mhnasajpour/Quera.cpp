#include "HourlyPay.h"
#include "Employee.cpp"
#include "HourlyPay.cpp"
#include "EmployeePay.cpp"

int main(){
    int n;
    cout << "How many checks do you want to print : ";
    cin >> n;

    for(int i = 0; i < n; i++){
        HourlyPay obj;
        
        string str;
        cout << "Name: "; 
        getchar();
        getline(cin,str);
        obj.setName(str);

        do{
            cout << "Social security number: ";
            cin >> str;
        }while(!obj.setSocialNum(str));

        do{
            cout << "Employee number: ";
            cin >> str;
        }while(!obj.setEmployeeNum(str));

        double num;
        do{
            cout << "Pay in a year: ";
            cin >> num;
        }while(!obj.setYearPay(num));

        int num1;
        do{
            cout << "How many hours did he/she work: ";
            cin >> num1;
        }while(!obj.sethoursWork(num1));

        /////////////////////////////////////////////////

        cout << "\n\n   Check\n" << "Name: " << obj.getName() << endl;
        cout << "Social security number: " << obj.getSocialNum() << endl;
        cout << "Employee number: " << obj.getEmployeeNum() << endl;
        cout << "Last week's salary: " << obj.processSalary() << "\n\n" << endl;
    }
}