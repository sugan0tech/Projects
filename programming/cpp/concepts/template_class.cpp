#include <iostream>
#include <string>
using namespace std;

template <class loosu>
class Node
{
public:
    loosu x;
    Node(loosu u)
    {
        x = u;
    };
    void display()
    {
        cout << x << endl;
    };
};

int main()
{
    Node<string> a("hi");
    Node<int> b(8);
    a.display();
    b.display();
}