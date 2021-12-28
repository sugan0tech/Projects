#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void SortUtil(int v, bool visited[],
                  stack<int> &Stack);

public:
    Graph(int V);
    void AddEdge(int v, int w);
    void Sort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::AddEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::SortUtil(int v, bool visited[],
                     stack<int> &Stack)
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            SortUtil(*i, visited, Stack);
    Stack.push(v);
}

void Graph::Sort()
{
    stack<int> Stack;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            SortUtil(i, visited, Stack);

    while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{
    Graph g(6);
    g.AddEdge(4, 2);
    g.AddEdge(5, 1);
    g.AddEdge(3, 2);
    g.AddEdge(5, 0);
    g.AddEdge(4, 0);
    g.AddEdge(4, 1);
    g.AddEdge(2, 3);
    g.AddEdge(3, 1);

    cout << "\nTopological Sort :";
    g.Sort();
    cout << endl;
    return 0;
}