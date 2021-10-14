/*Write three derived classes inheriting functionality of base class 
person (should have a member function that ask to enter name and age)
and with added unique features of student, and employee, and 
functionality to assign, change and delete records of student and employee. . 
 Create two objects of derived classes each */
#include <iostream>
#include <string.h>
using namespace std;

class person
{
protected:
    string name;
    int age;

public:
    void get_data()
    {
        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter the age: ";
        cin >> age;
    }

    void show_data()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age;
    }

    void print_address(void)
    {
        cout << "\n The address of object is " << this;
    }
};

class student : public person
{
private:
    int ID;

public:
    void get_data()
    {
        cout << "Enter the information for student" << endl;
        person::get_data();
        cout << "Enter Student ID: ";
        cin >> ID;
    }
    void show_data()
    {
        cout << "The information on student is" << endl;
        person::show_data();
        cout << "\nID : " << ID;
    }
};

class employee : public person
{
private:
    long int salary;

public:
    void get_data()
    {
        cout << "Enter the information on employee " << endl;
        person::get_data();
        cout << "Enter Emplyee's salary: ";
        cin >> salary;
    }
    void show_data()
    {
        cout << "\nThe information on Employee is ";
        person::show_data();
        cout << "\nSalary: " << salary << endl;
    }
};

int main()
{
    student stu;
    employee employee;
    stu.get_data();
    employee.get_data();
    stu.show_data();
    employee.show_data();
    stu.print_address();
    employee.print_address();

    cout << "\nAddress space used by employee: " << sizeof(employee) << "\nAddress space user by student : " << sizeof(stu) << endl;
    return 0;
}