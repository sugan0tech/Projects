#include <iostream>
#include <string.h>
using namespace std;

class complex
{
public:
    int real;
    int img;
    // default constructor
    complex()
    {
        real = 0;
        img = 0;
    }
    // parameterised constructor
    complex(int x, int y)
    {
        real = x;
        img = y;
    }
    // copy constructor (just copies data from another object)
    complex(complex *obj)
    {
        real = obj->real;
        img = obj->img;
    }
    void display()
    {
        cout << "\n"
             << real << " + " << img << "i";
    }
};

int main()
{
    //default constructor
    complex obj;
    obj.display();
    // parameterised constructor
    complex c = complex(1, 2);
    complex c1(3, 4);
    //copy constructor
    complex c2(c);

    c.display();
    c1.display();
    c2.display();
}