#include <iostream>
#include <string>
using namespace std;

class Test
{
    private:
        int t_code, no_cand, no_cent;
        string desc;
        int CALCNTR();
    
    public:
        void SCHEDULE();
        void DISPTEST();
};

void Test::SCHEDULE()
{
    cout<<"Enter the Test Code : ";
    cin>>t_code;
    cout<<"\nEnter the Description : ";
    cin.get();
    getline(cin,desc);
    cout<<"\nEnter the No. of Candidates : ";
    cin>>no_cand;
}

int Test::CALCNTR()
{
    no_cent = (no_cand/100) + 1;
    return no_cent;
}

void Test::DISPTEST()
{
    cout<<"\n Details";
    cout<<"\nTest Code : "<<t_code;
    cout<<"\nDescription : "<<desc;
    cout<<"\nNo. of Candidates : "<<no_cand;
    cout<<"\nNo. of Centers : "<<CALCNTR();
}

int main()
{
    Test t1;
    t1.SCHEDULE();
    t1.DISPTEST();
    return 0;
}