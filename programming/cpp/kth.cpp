#include <iostream>
using namespace std;
class rational
{
private:
    int p;
    int q;

public:
    rational()
    {
        p = 0;
        q = 0;
    }
    rational(int x, int y)
    {
        p = x;
        q = y;
    };
    void display()
    {
        cout << p << "/" << q << endl;
    }
    friend rational operator+(rational r1, rational r2);
};
rational operator+(rational r1, rational r2)
{
    rational t;
    t.p = r1.p * r2.q + r1.q * r2.p;
    t.q = r1.q * r2.q;
    return t;
};

int main()
{
    rational r1(3, 4);
    rational r2(2, 5);
    rational r3;
    r1.display();
    r2.display();
    r3 = r1 + r2;
    r3.display();
    return 0;
}