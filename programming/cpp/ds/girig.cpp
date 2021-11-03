#include <iostream>
#define MAX 5

using namespace std;
int front = -1;
int rear = -1;
int Queue[MAX];
int vis[MAX] = {0, 0, 0, 0, 0};
int a[5][5] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 0},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 0, 1, 1, 0}};

void enqueue(int ele)
{

    if (rear == MAX - 1)
        cout << "Queue is Full";
    else
    {
        if (front == -1)
        {
            front = rear = 0;
            Queue[rear] = ele;
        }
        else
            Queue[++rear] = ele;
    }
}

int dequeue()
{
    int out;
    if (front == -1)
    {
        return 0;
    }
    else
    {
        if (front == rear)
            front = rear = -1;
        else
        {
            out = Queue[front];
            front++;
        }
        return out;
    }
    return 0;
}

void bfs(int s, int n)
{
    int p, i;
    enqueue(s);
    vis[s] = 1;
    p = dequeue();
    if (p != 0)
        cout << p;
    while (p != 0)
    {
        for (i = 1; i <= n; i++)
        {
            if ((a[p][i] != 0) && (vis[i] == 0))
            {
                enqueue(i);
                vis[i] = 1;
            }
            p = dequeue();
            if (p != 0)
                cout << p;
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            bfs(i, n);
    }
}

int main()
{
    int n = 5;
    cout << "the adjacency matrix is \n";
    cout << "   1 2 3 4 5\n\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "  ";
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    bfs(1, n);
}