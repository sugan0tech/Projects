#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int man_hattan(int x1, int x2, int y1, int y2)
{
    int res = abs(x1 - x2) + abs(y1 - y2);
    if (res == 1)
        return 1;
    return 0;
}

int main()
{
    int T;
    cin >> T;
    while (T)
    {
        int n, m;
        cin >> n;
        cin >> m;
        int mat[n * 4][2];
        for (int i = 0; i < n * 4; i++)
        {
            mat[i][0] = 0;
            mat[i][1] = 0;
        }
        int holder = n * 4;
        int i = 0;
        for (i = 0; i < n; i++)
        {
            mat[i][0] = i;
            mat[i][1] = 0;
        }
        for (i; i < n * 2; i++)
        {
            mat[i][0] = 0;
            mat[i][1] = i;
        }
        for (int i = 0; i < n * 4; i++)
        {
            cout << mat[i][0];
            cout << mat[i][1];
        }

        T--;
    }

    return 0;
}