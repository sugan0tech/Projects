#include<iostream>
#include<string.h>
using namespace std;
void func()
{
    static int count = 0;
    count++;
    cout<< "Count val : " << count << endl;
}

int main()
{
    for(int i = 0 ; i <= 5; i++)
    {
        func();
    }
}