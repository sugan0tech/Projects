/*Write a program to calculate bonus of the employees. The class master 
derives the information from both admin and account classes which derives information 
from class person. Create base and all derived classes having same member functions 
called getdata, display data and bonus. Create a base class pointer that capable of 
accessing data of any class and calculates bonus of the specified employee. Use virtual functions*/

#include <iostream>
#include <string.h>
using namespace std;

class person
{
        int id;
        string name;

public:
        virtual void getdata();
        virtual void display();
        virtual void bonus();
};

void person ::getdata()
{
        cout << "\n Enter the name and number of the employee: " << endl;
        cin >> name >> id;
}

void person ::display()
{
        cout << "\n Employee Name  = " << name << "\n Number =  " << id;
}

void person ::bonus()
{
        cout << "\n Bonus function of person base class is called ";
}

class admin : public virtual person
{
        int sale_admin;

public:
        void getdata();
        void display();
        void bonus();
};

void admin ::getdata()
{
        cout << "\n Enter the Sale amount of the admin : " << endl;
        cin >> sale_admin;
}

void admin ::display()
{
        cout << "\n Admin Employee sale amount  = " << sale_admin;
}

void admin ::bonus()
{
        if (sale_admin > 2000)
                cout << "\n The bonus of the admin is : " << (sale_admin * 0.25);
}

class account : public virtual person
{
        long int amt;

public:
        void getdata();
        void display();
        void bonus();
};

void account ::getdata()
{
        cout << "\n Enter the amount accumulated in the account : " << endl;
        cin >> amt;
}

void account::display()
{
        cout << "\n Employee Account amount  = " << amt;
}

void account ::bonus()
{
        if (amt > 10000)
                cout << "\n The bonus of the admin is : " << (amt * 0.25);
}

class master : public admin, public account
{
public:
        void getdata();
        void display();
        void bonus();
};

void master ::getdata()
{
        cout << "\n Executing getdata of master class :";
        person::getdata();
        admin::getdata();
        account::getdata();
}

void master ::display()
{
        cout << "\n executing display of master class :";
        person::display();
        admin::display();
        account::display();
}

void master ::bonus()
{
        cout << "\n executing bonus of master class :";
        person::bonus();
        admin::bonus();
        account::bonus();
}

int main()
{
        person p, *per_ptr;
        admin a, *admin_ptr;
        account ac, *acc_ptr;
        master ms, *ms_ptr;
        cout << "\nassigning the addr of base class person to base class pointer ";
        per_ptr = &p;
        per_ptr->getdata();
        per_ptr->display();
        per_ptr->bonus();
        cout << "\n assigning the addr of admin class to base class pointer ";
        per_ptr = &a;
        per_ptr->getdata();
        per_ptr->display();
        per_ptr->bonus();
        cout << "\n assigning the addr of account class to base class pointer ";
        per_ptr = &ac;
        per_ptr->getdata();
        per_ptr->display();
        per_ptr->bonus();
        cout << "\n assigning the addr of class master to base class pointer ";
        per_ptr = &ms;
        per_ptr->getdata();
        per_ptr->display();
        per_ptr->bonus();
        return 0;
}