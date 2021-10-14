#include<iostream>
#include<string.h>
using namespace std;

inline int max(int a, int b) { return (a > b)?1:0; }

int main()
{
    int a = 10, b = 20;
    cout<<max(a,b)<<endl;
}