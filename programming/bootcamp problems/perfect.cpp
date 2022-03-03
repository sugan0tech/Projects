#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter the element: ";
    cin >> n;
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            count += i;
        }
    }

    if (count == n)
    {
        cout << "perfect";
    }
    else
        cout << "not perfect";

    return 0;
}