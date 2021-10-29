#include <bits/stdc++.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Node
{
public:
    int vertex;
    int weight = 0;
    int view = 0;
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

class Queue
{
public:
    int size, rear = -1, front = -1;
    vector<int> qeue;
    void enqeue(int n)
    {
        if (rear = -1)
        {
            qeue.push_back(n);
            rear++;
            front++;
        }
        else
        {
            qeue.push_back(n);
            ++rear;
        }
    }

    int deqeue()
    {
        int tmp = qeue[rear];
        qeue.pop_back();
        rear--;
        return tmp;
    }

    void print()
    {
        for (int i = 0; i < qeue.size(); i++)
        {
            cout << qeue[i];
        }
    }
};

int main()
{
    int v;
    Queue que;
    v = 5;
    List AdjList[5];
    int visit[5] = {0, 0, 0, 0, 0};
    // int i = 0;
    // while (i <= v)
    // {
    //     List tmp;
    //     printf("Enter the adjacents of vertice {%d}\n", i);
    //     tmp.create();
    //     AdjList[i] = tmp;
    //     i++;
    // };
    Node *tmp, *ne;
    tmp = new Node;
    tmp->vertex = 1;
    ne = new Node;
    ne->vertex = 4;
    tmp->next = ne;
    AdjList[0].head = tmp;

    tmp = new Node;
    tmp->vertex = 0;
    ne = new Node;
    ne->vertex = 4;
    tmp->next = ne;
    ne = new Node;
    ne->vertex = 3;
    tmp->next->next = ne;
    ne = new Node;
    ne->vertex = 2;
    tmp->next->next->next = ne;
    AdjList[1].head = tmp;

    tmp = new Node;
    tmp->vertex = 1;
    ne = new Node;
    ne->vertex = 3;
    tmp->next = ne;
    AdjList[2].head = tmp;

    tmp = new Node;
    tmp->vertex = 1;
    ne = new Node;
    ne->vertex = 2;
    tmp->next = ne;
    ne = new Node;
    ne->vertex = 4;
    tmp->next->next = ne;
    AdjList[3].head = tmp;

    tmp = new Node;
    tmp->vertex = 0;
    ne = new Node;
    ne->vertex = 1;
    tmp->next = ne;
    ne = new Node;
    ne->vertex = 3;
    tmp->next->next = ne;
    AdjList[4].head = tmp;
    int i = 0;
    while (i < v)
    {
        printf("\n [%d] : -> ", i);
        AdjList[i].display();
        i++;
    }
    cout << "\n";
    cout << "--------------------------------\n";
    cout << "--------------------------------\n";
    cout << "--------------------------------\n";
    i = 0;
    int t = 0;
    que.enqeue(0);
    while (i < v)
    {
        Node *tmp = AdjList[i].head;
        while (tmp != NULL)
        {
            if (visit[tmp->vertex] == 0)
            {
                que.enqeue(tmp->vertex);
                visit[tmp->vertex] = 1;
            }
            tmp = tmp->next;
        }
        visit[i] = 1;
        i++;
    }
    que.print();
}
