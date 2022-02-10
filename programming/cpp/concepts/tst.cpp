#include <iostream>
#include <string.h>
using namespace std;
class A
{
private:
    int val;
    static int obj_count; // static member
public:
    void f(int v)
    {
        val = v;
        obj_count++;
    }
    void p()
    {
        cout << obj_count << endl;
        cout << this->val << endl;
    }
    static void count() // static member function
    {
        cout << obj_count;
    }
};

int A::obj_count = 0; // must to be initialied outside of class : common val for all the class no matter how many times you declare

int main()
{
    A obj1;
    obj1.f(8);
    A obj2;
    obj2.f(9);
    obj2.count();
}