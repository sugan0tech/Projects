#include <iostream>
#include <string.h>
using namespace std;
class circle
{
private:
    double radius;

public:
    void store(double r);
    double area(void);
    void display(void);
};

// member functions
void circle::store(double r)
{
    radius = r;
}
void circle::display(void)
{
    std::cout << "\nradius : " << radius;
}
double circle::area(void)
{
    return 3.14 * radius * radius;
}

int main(void)
{
    circle c;
    c.store(8);
    std::cout << "\narea : " << c.area();
    c.display();
}