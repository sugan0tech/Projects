#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int sum = 0, count = 0;
    string str;
    cout<<"Enter the String : ";
    cin>>str;
    for (char ch:str)
    {
        if(isdigit(ch))
        {
            sum += (ch - 48);
            count++;
        }
    }
    cout<<"\n\nSum of Digits :"<<sum;
    cout<<"\n\nCount of Digits :"<<count;
    return 0;
}