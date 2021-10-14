/*Write a program to accept five different numbers by creating a class called friendfunc1 
and friendfunc2 taking 2 and 3 arg respectively and calculate the average of these numbers 
by passing object of the class to friend function.*/
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class friendfunc1
{
public:
    int num1, num2;

public:
    friend int avg();
};

class friendfunc2
{
public:
    int num3, num4, num5;

public:
    friend int avg();
};

int avg(friendfunc1 temp1, friendfunc2 temp2)
{
    double res;
    res = (temp1.num1 + temp1.num2 + temp2.num3 + temp2.num4 + temp2.num5) / 5;
    return res;
};

int main()
{
    friendfunc1 temp1;
    friendfunc2 temp2;
    temp1.num1 = 1;
    temp1.num2 = 2;
    temp2.num3 = 3;
    temp2.num4 = 4;
    temp2.num5 = 5;

    cout << "Average " << avg(temp1, temp2) << endl;
    return 0;
    // 20EUCS147 Sugavanesh M
};