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
    int opt;
    cout << "Enter the options :\n1 for custom value\n2 for default value\n";
    cin >> opt;

    switch (opt)
    {
    case 1:
    {
        cout << "Enter the numberr of Vertices :";
        cin >> v;
        List AdjList1[v];
        int visit1[v];
        int i;
        for (i = 0; i < v; i++)
        {
            visit1[i] = 0;
        }
        i = 0;
        while (i <= v)
        {
            List tmp;
            printf("Enter the adjacents of vertice {%d}\n", i);
            tmp.create();
            AdjList1[i] = tmp;
            i++;
        };
        i = 0;
        cout << "\n\nThe given graph is : \n\n";
        while (i < v)
        {
            printf("\n [%d] : -> ", i);
            AdjList1[i].display();
            i++;
        }
        cout << "\n\nBFS value :";
        i = 0;
        que.enqeue(AdjList1[0].head->vertex);
        while (i < v)
        {
            Node *tmp = AdjList1[i].head;
            while (tmp != NULL)
            {
                if (visit1[tmp->vertex] == 0)
                {
                    que.enqeue(tmp->vertex);
                    visit1[tmp->vertex] = 1;
                }
                tmp = tmp->next;
            }
            visit1[i] = 1;
            i++;
        }
        que.print();
        cout << endl;
        break;
    }

    case 2:
    {
        v = 5;
        List AdjList2[5];
        int visit2[5] = {0, 0, 0, 0, 0};
        Node *tmp, *ne;
        tmp = new Node;
        tmp->vertex = 1;
        ne = new Node;
        ne->vertex = 4;
        tmp->next = ne;
        AdjList2[0].head = tmp;

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
        AdjList2[1].head = tmp;

        tmp = new Node;
        tmp->vertex = 1;
        ne = new Node;
        ne->vertex = 3;
        tmp->next = ne;
        AdjList2[2].head = tmp;

        tmp = new Node;
        tmp->vertex = 1;
        ne = new Node;
        ne->vertex = 2;
        tmp->next = ne;
        ne = new Node;
        ne->vertex = 4;
        tmp->next->next = ne;
        AdjList2[3].head = tmp;

        tmp = new Node;
        tmp->vertex = 0;
        ne = new Node;
        ne->vertex = 1;
        tmp->next = ne;
        ne = new Node;
        ne->vertex = 3;
        tmp->next->next = ne;
        AdjList2[4].head = tmp;
        int j = 0;
        cout << "\n\nThe given graph : \n\n";
        while (j < v)
        {
            printf("\n [%d] : -> ", j);
            AdjList2[j].display();
            j++;
        }
        cout << "\n\nBFS value :";
        j = 0;
        que.enqeue(0);
        while (j < v)
        {
            Node *tmp = AdjList2[j].head;
            while (tmp != NULL)
            {
                if (visit2[tmp->vertex] == 0)
                {
                    que.enqeue(tmp->vertex);
                    visit2[tmp->vertex] = 1;
                }
                tmp = tmp->next;
            }
            visit2[j] = 1;
            j++;
        }
        que.print();
        cout << endl;

        break;
    }
    }
}
