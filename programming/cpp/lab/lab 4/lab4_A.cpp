/*Write a program to search a key element in a given set of elements using class template.*/
#include <iostream>
#include <string.h>
using namespace std;

template <class T>
class spl_ar
{
public:
    T arr[100];
    int size;
    void create()
    {
        cout << "\nEnter the size";
        cin >> size;
        for (int i = 0; i < size; i++)
        {
            cout << "\nenter the element :";
            cin >> arr[i];
        }
    }
    void search(T var)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == var)
            {
                cout << "\nFound it " << arr[i] << endl;
            }
        }
    }
};

int main()
{
    spl_ar<int> objI;
    spl_ar<char> objC;
    objI.create();
    objI.search(3);
    objC.create();
    objC.search('c');
}