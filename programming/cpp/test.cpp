#include <iostream>
using namespace std;
class complex
{
public:
    int a;
    int b;
    void print()
    {
        cout << "\n"
             << a << " + i" << b << "\n";
    }
    complex(int x, int y)
    {
        this->a = x;
        this->b = y;
    }
    void add(int x, int y)
    {
        a = a + x;
        b = b + y;
    }
};
int main()
{

    complex selva(5, 6);
    selva.add(2, 3);
    selva.print();
    return 0;
}
