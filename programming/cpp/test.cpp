#include <iostream>
using namespace std;
template <typename T>
T maxx(T x, T y)
{
    if (x > y)
        return x;
    else
        return y;
}

int main()
{
    int c = maxx<int>(10, 5);
    float d = maxx<float>(4.5f, 6.8f);
    cout << c << d;
    return 0;
}