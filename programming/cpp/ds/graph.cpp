#include <bits/stdc++.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Queue
{
public:
    int size, rear = -1, front = -1;
    vector<int> qeue;
    void enqeue();
    int deqeue();
    void print();
    void Queue::enqeue()
    {
        int n;
        cout << "\nEnter the num :";
        cin >> n;
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

    int Queue::deqeue()
    {
        int tmp = qeue[rear];
        qeue.pop_back();
        rear--;
        return tmp;
    }

    void Queue::print()
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
    cout << "\nEnter the number of vertices";
    cin >> v;
}
