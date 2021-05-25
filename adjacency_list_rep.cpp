#include <iostream>
#include <vector>
using namespace std;

#define V 5

void addedge(vector<int> graph[], int u, int v)
{
    graph[u].emplace_back(v);
}

int main()
{
    vector<int> graph[V];

    addedge(graph, 0, 1);
    addedge(graph, 0, 4);
    addedge(graph, 1, 1);
    addedge(graph, 1, 2);
    addedge(graph, 1, 3);
    addedge(graph, 1, 4);
    addedge(graph, 3, 2);
    addedge(graph, 3, 4);

    cout << "Adjacency List: " << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i;
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << " -> " << graph[i][j];
        }
        cout << endl;
    }
    return 0;
}