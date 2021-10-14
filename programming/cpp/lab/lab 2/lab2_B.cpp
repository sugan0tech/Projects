#include <iostream>
using namespace std;

class Report
{
    private:
        char admn_num[4];
        char name[20];
        float marks[5];
        float avg;
        void GETAVG();
    
    public:
        void READINFO();
        void DISPLAYINFO();
};

void Report::GETAVG()
{
    avg = (marks[0] + marks[1] + marks[2] + marks[3] + marks[4])/5;
}

void Report::READINFO()
{
    cout<<"Enter the Student Details";
    cout<<"\nAdmission Number : ";
    cin>>admn_num;
    cout<<"\nName of the Student : ";
    cin>>name;
    cout<<"\nEnter the Marks in 5 Sub : ";
    for(int i = 0;i < 5; i++)
    {
        cin>>marks[i];
    }
    
    GETAVG();
}

void Report::DISPLAYINFO()
{
    cout<<"\nThe details are";
    cout<<"\nAdmission Number : "<<admn_num;
    cout<<"\tName of the Student : "<<name;
    cout<<"\tMarks in 5 Subjects :";
    for(int i = 0; i < 5; i++)
    {
        cout<< " " <<marks[i];
    }
    cout<<"\tAverage Mark : "<<avg <<"\n";
}

int main()
{
    Report s1;
    s1.READINFO();
    s1.DISPLAYINFO();
    
    return 0;
}