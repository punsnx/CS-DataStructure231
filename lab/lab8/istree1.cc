#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<int> > adj;
unordered_map<int, int> parentMap;
vector<bool> visited;
vector<int> cycle;


void addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}
bool dfs(int s, int parent){
    visited[s] = true;
    parentMap[s] = parent;
    sort(adj[s].begin(),adj[s].end());

    for (int adj : adj[s]){
        if (!visited[adj]){
            if (dfs(adj, s)){
                return true;
            }
        }
        else if (adj != parent){
            cycle.push_back(adj);
            int current = s;
            while (current != adj){
                cycle.push_back(current);
                current = parentMap[current];
            }
            cycle.push_back(adj);
            return true;
        }
    }
    return false;
}

bool isTree(int V){
    if (dfs(1, -1)){
        return false;
    }
    for (int i = 1; i <= V; i++){
        if (!visited[i]){
            return false;
        }
    }
    return true;
}

int main(){
    int V, E;
    cin >> V >> E;
    adj.resize(V + 1);
    visited.resize(V + 1, false);
    for (int i = 0; i < E; i++){
        int a, b;
        cin >> a >> b;
        addEdge(a, b);
    }
    if (isTree(V)){
        cout << "Is a tree" << endl;
    }
    else{
        cout << "Cycle exists with vertex ";
        for (int i = cycle.size() - 1; i > 0; i--){
            cout << cycle[i] << " ";
        }
        cout << endl;
        cout << "Is not a tree" << endl;
    }
}
