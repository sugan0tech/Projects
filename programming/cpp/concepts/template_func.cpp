#include<iostream>
using namespace std;

template<typename T>
T mx(T m,T n)
{

    if(m>n)
        return m;
    else
        return n;
}

template<class T>
T mx2(T m,T n)
{

    if(m>n)
        return m;
    else
        return n;
}

int main()
{
    int a=10,b=20;
    float x=5.8f,y=4.9f;
    int r = mx<int>(a,b);
    float re = mx2(x,y);
    cout<<r<<endl<<re;
    return 0;
}