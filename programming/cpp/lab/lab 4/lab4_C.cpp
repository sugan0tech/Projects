/*Write a C++ program to find the read two data items and find the sum using class template*/
#include <iostream>
#include <string.h>
using namespace std;

template <class T>
class cls
{
public:
    T data1, data2;
    void create()
    {
        cout << "Enter the 2 datas :";
        cin >> data1 >> data2;
    }
    void sum()
    {
        cout << "their sum : " << data1 + data2 << endl;
    }
};

int main()
{
    cls<int> objI;
    objI.create();
    cls<float> objF;
    objF.create();
    cls<double> objD;
    objD.create();
    objI.sum();
    objF.sum();
    objD.sum();
}