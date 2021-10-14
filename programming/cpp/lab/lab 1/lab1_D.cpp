#include <iostream>
using namespace std;

int main()
{
    int choice, n;
    char ch;
    cout<<"Select any option : \n";
    cout<<"1 To check whether character is uppercase or lowercase.\n2 To check whether the given number is odd or even\n";
    cin>> choice;
    switch(choice)
    {
        case 1:
            cout<<"Enter The Character :";
            cin>>ch;
            if (ch >= 'A' && ch <= 'Z')
                cout<<ch<<" is an UpperCase character\n";
            else if (ch >= 'a' && ch <= 'z')
                cout<<ch<<" is an LowerCase character\n";
            else
                cout<<"Invalid Input! Not an Aplhabetical Character\n";
            break;
        case 2:
            cout<<"Enter The Num : ";
            cin>>n;
            if(n%2 == 0)
                cout<<n<<"Even";
            else
            cout<<n<<"Odd";
            break;
    }
    return 0;
}