#include <iostream>
using namespace std;

int main()
{
    int BS;
    float DA, HRA, conv,gross;
    cout<<"Enter Basic Salary :";
    cin>>BS;

    if (BS >= 5000)
    {
        DA = 1.1 * BS;
        HRA = 0.2 * BS;
        conv = 500;
        gross = BS + DA + HRA + conv;
        cout<<"\nThe Goss Salary : "<<gross;
    }
    else if(BS >= 3000 && BS < 5000)
    {
        DA = 1.0 * BS;
        HRA = 0.15 * BS;
        conv = 400;
        gross = BS + DA + HRA + conv;
        cout<<"\nThe Goss Salary is Rs."<<gross;
    }
    else
        cout<<"Low income";
    
    return 0;
}