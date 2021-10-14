#include<iostream>
#include<string.h>
using namespace std;

class student
{
    public:
        string name="unknown", address="not available";
        int age = 0;
        void setinfo(string Name, int Age)
        {
            name = Name;
            age = Age;
        }
        void setinfo(string Name ,int Age ,string Address)
        {
            name = Name;
            age = Age;
            address = Address;
        }
        void display()
        {
            cout<<"Name : "<< name << " Age : "<< age << " Address : "<< address;

        }
};

int main()
{

    student cse_c[10];
    int Age, n;
    string Name, Address;

    cout<<"Enter the count of students : ";
    cin>>n;

    for(int i=0; i < n; i++)
    {
        cout << "Enter the Name of student " << i << " : ";
        cin>> Name;
        cout << "Enter the Age of student " << i << " : ";
        cin>> Age;
        cout << "Enter the Address of student " << i << " : ";
        cin>> Address;
        cse_c[i].setinfo(Name, Age, Address);
    }

    for(int i=0; i < 10; i++)
    {
        cout << "Student " << i << "Name : "<< cse_c[i].name<<endl;
        cout << "Student " << i << "Age : "<< cse_c[i].age<<endl;
        cout << "Student " << i << "Address : "<< cse_c[i].address<<endl;
    }
    return 0;
}