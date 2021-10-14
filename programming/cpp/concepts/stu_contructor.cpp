#include<iostream>
#include<string.h>
using namespace std;

class student
{
    private:
        string name, dept, sec;
        int roll_no;
        float score1, score2;

    public:
        void set(void);
        void display(void);

        student(int mark1, int mark2)
        {
            score1 = mark1;
            score2 = mark2;
        }

};


void student::display(void)
{
    cout << "Student Name : " << name ;
    cout << "\nCGPA score 1: " << score1;
    cout << "\nCGPA score 2: " << score2;

}


int main()
{
    int n;
    cout << "Enter the total number of students : ";
    cin >> n;
    student skcet(1, 2);
    skcet.display();

}