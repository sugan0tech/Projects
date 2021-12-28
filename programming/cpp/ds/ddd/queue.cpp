#include <iostream>
using namespace std;
int front = -1, rear = -1, queue[50];
void enqueue(int x)
{
    if (rear == -1)
        front = 0, rear = 0;
    queue[front++] = x;
}
int dequeue()
{
    if (front > 0)
        return queue[front--];
    else
        return 0;
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    for (int i = 0; i < front; i++)
    {
        cout << queue[i];
    }
    cout << endl;
    return 0;
}