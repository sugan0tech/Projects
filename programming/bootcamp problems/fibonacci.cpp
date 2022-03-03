#include <iostream>
using namespace std;

int fib(int n)
{
    if (n < 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cin >> n;
    int a = 0, b = 1, c;
    while (n)
    {
        c = a + b;
        a = b;
        b = c;
        n--;
        cout << c << " ";
    }
    cout << endl;
    cout << fib(8);

    return 0;
}