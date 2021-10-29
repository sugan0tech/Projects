#include <stdlib.h>
#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
using namespace std;

class Node
{
public:
    int vertex;
    int weight = 0;
    Node *next;
};

class List
{
public:
    Node *head = NULL;
    void create()
    {
        int N;
        Node *temp, *neww;
        cout << "Enter the data : ";
        cin >> N;
        while (N)
        {
            neww = new Node;
            neww->vertex = N;
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

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << (*temp).vertex;
            temp = (*temp).next;
            cout << " -> ";
        }
        cout << "  /";
    }
};

int main()
{
    List ll;
    ll.create();
    ll.display();

    int v;

    cout << "\nEnter the number of vertices ";
    cin >> v;
    List AdjList[v];
    int i = 0;
    while (i <= v)
    {
        List tmp;
        tmp.create();
        AdjList[i] = tmp;
        i++;
    };
    i = 0;
    while (i <= v)
    {
        printf("\n [%d] : -> ", i);
        AdjList[i].display();
        i++;
    }
    cout << endl;
}