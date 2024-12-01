#include <iostream>
#include <list>
using namespace std;

class Graph{
private:
    int V;
    list<int> *adj;
    void dfsVisit(int s,bool visited[]);
public:
    Graph(int V){
        this->V = V;
        this->adj = new list<int>[V];
    }
    void addGraph(int v,int w){
        adj[v].push_back(v)
        adj[w].push_
    }

};