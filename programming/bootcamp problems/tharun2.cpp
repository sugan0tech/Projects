#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;
int main()
{

    int n, temp, count;

    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "\nEnter the elements of the array: ";
    int a[n], b[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n - 1; k++)
        {
            if (a[k] > a[k + 1])
            {
                temp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = temp;
            }
        }
    }
    int min = a[0];
    int max = a[n - 1];
    int diff = max - min;
    int ptr = 0;
    bool boo = false;
    for (int i = 1; i < diff; i++)
    {
        for (int j : a)
        {
            if (j == min + i)
                boo = true;
        }
        if (!boo)
            cout << min + i;
    }

    return 0;
}