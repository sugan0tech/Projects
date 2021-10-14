#include<iostream>
#include<string.h>
using namespace std;

class Marks
{
    public:
    int m1, m2, m3;
    friend void avg();//global function as friend
};
void avg(Marks stu)
{
    int avg = (stu.m1 + stu.m2 + stu.m3)/3;
    cout<<"Avg :"<<avg<<endl;
}

int main()
{
    Marks student;
    student.m1 = 50;
    student.m2 = 70;
    student.m3 = 80;
    avg(student);
}