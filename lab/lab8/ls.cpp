#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

unordered_map<int, int> parent_map;
vector<int> cycle_path;

void bubbleB(vector<int> &lst)
{
    int n = lst.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (lst[j] > lst[j + 1])
            {
                swap(lst[j], lst[j + 1]);
            }
        }
    }
}

void addEdge(int a, int b)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
}

bool DFS(int node, int parent)
{
    visited[node] = true;
    parent_map[node] = parent;

    bubbleB(graph[node]);

    for (int adj : graph[node])
    {
        if (!visited[adj])
        {
            if (DFS(adj, node))
            {
                return true;
            }
        }
        else if (adj != parent)
        {
            cycle_path.push_back(adj);
            int current = node;
            while (current != adj)
            {
                cycle_path.push_back(current);
                current = parent_map[current];
            }
            cycle_path.push_back(adj);
            return true;
        }
    }
    return false;
}

bool isTree(int V)
{
    if (DFS(1, -1))
    {
        return false;
    }
    for (int i = 1; i <= V; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int V, E;
    cin >> V >> E;
    graph.resize(V + 1);
    visited.resize(V + 1, false);
    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        addEdge(a, b);
    }
    if (isTree(V))
    {
        cout << "Is a tree" << endl;
    }
    else
    {
        cout << "Cycle exists with vertex ";
        for (int i = cycle_path.size() - 1; i > 0; i--)
        {
            cout << cycle_path[i] << " ";
        }
        cout << endl;

        cout << "Is not a tree" << endl;
    }
}
