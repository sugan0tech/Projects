#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    void addEdge(int v, int w);

    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS(int v)
{
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

int main()
{
    Graph graph;
    graph.addEdge(1, 2);
    graph.addEdge(2, 4);
    graph.addEdge(1, 3);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(4, 2);

    graph.DFS(1);
    cout << endl;

    return 0;
}
