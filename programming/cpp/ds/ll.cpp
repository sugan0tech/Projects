#include <iostream>
#include <string.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *head = NULL;
    void create();
    void display();
};

void LinkedList::create()
{
    int N;
    Node *temp, *neww;
    cout << "Enter the data : ";
    cin >> N;
    while (N)
    {
        neww = new Node;
        neww->data = N;
        neww->next = NULL;
        if (head == NULL)
        {
            head = neww;
            temp = head;
        }
        else
        {
            temp->next = neww;
            temp = neww;
        }
        cout << "Enter the data : ";
        cin >> N;
    }
};

void LinkedList::display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << " -> " << (*temp).data;
        temp = (*temp).next;
    }
}
int main()
{
    LinkedList ll;
    ll.create();
    ll.display();
}