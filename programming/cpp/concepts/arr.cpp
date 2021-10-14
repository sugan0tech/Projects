#include<iostream>
#include<string.h>
using namespace std;

class student
{
    private:
        string name, dept, sec;
        int roll_no;
        float score;
    public:
        void set(void);
        void display(void);


};

void student::set(void)
{
    cout << "Student Name : ";
    cin >> name;
    cout << "\nRoll No : ";
    cin >> roll_no;
    cout << "\nCGPA score : ";
    cin >> score;
    cout << "\nDepartment : ";
    cin >> dept;
    cout << "\nSection :";
    cin >> sec;

}

void student::display(void)
{
    cout << "Student Name : " << name ;
    cout << "\nRoll No : " << roll_no;
    cout << "\nCGPA score : " << score;
    cout << "\nDepartment : " << dept;
    cout << "\nSection :" << sec;

}


int main()
{
    int n;
    cout << "Enter the total number of students : ";
    cin >> n;
    student skcet[n];
    for (int i = 0; i < n; i++)
    {
        skcet[i].set();
    }
    for (int i = 0; i < n; i++)
    {
        skcet[i].display();
    }

}