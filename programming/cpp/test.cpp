#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *link;
};
void display(node *n)
{

    while (n != NULL)
    {
        cout << "VAlue is " << n->data << endl;
        n = n->link;
    }
}
void deletelist(node *head, int pos)
{
    node *temp = head;
    pos--;
    while (pos)
    {
        temp = temp->link;
        pos--;
    }
    temp->link = temp->link->link;
}
int main()
{
    int position, element, delposition;
    node *head = new node();
    node *first = new node();
    node *second = new node();
    head->data = 10;
    head->link = first;
    first->data = 20;
    first->link = second;
    second->data = 30;
    second->link = NULL;
    deletelist(head, 1);
    display(head);
    return 0;
}