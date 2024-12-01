#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Graph{
    int n;
    vector<int> *adj;
public:
    Graph(int n){
        this->n = n+1;
        adj = new vector<int>[n+1];
    }
    void addNode(int v,int w){
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    void dfs(int S,int s,vector<bool> visited){
        visited[s] = true;
        for(int &v : adj[s]){
            if(!visited[v]){
                dfs(S,v,visited);
            }else if(v == S){
                for(int i = 0;i<n;i++){
                    if(visited[i] == true)cout << i << " ";
                }
                cout << endl;
                return;
            }
        }
    }
};



int main(){
    int V,E;
    cin >> V >> E;
    Graph t(V);
    for(int i = 0;i<E;i++){
        int A,B;
        cin >> A >> B;
        t.addNode(A,B);
    }
    vector<bool> visited(V+1,false);
    t.dfs(1,1,visited);


}