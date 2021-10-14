#include <iostream>
using namespace std;

int main()
{
    int N;
    cout<<"\nGive N :";
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cout<<"\nPass "<<i<<" : ";
        for(int j=1; j<=N; j++)
            cout<<j<<" ";
    }
    return 0;
}