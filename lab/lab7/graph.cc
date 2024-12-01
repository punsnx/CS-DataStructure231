#include <iostream>
#include <vector>
using namespace std;

typedef struct _Edge{
    string edge;
    int vertex;
}Edge;

class Graph{
    int nVertex;
    vector<Edge> *adjList;
public:
    Graph(int v){
        this->nVertex = v;
        this->adjList = new vector<Edge>[v];
    }
    Edge newEdge(int w,string name){
        Edge edge = {name,w};
        return edge;
    }
    void addEdge(int v,int w,string edge){
        adjList[v].push_back(newEdge(w,edge));
        adjList[w].push_back(newEdge(v,edge));
    }
    void printAdjList(){
        for(int v = 0;v < this->nVertex;v++){
            cout << v;
            size_t edgeSize = adjList[v].size();
            for(int e = 0;e < edgeSize ;e++){
                cout << "->" << adjList[v][e].edge << "(" << adjList[v][e].vertex << ")";
            }
            cout << "->NULL" << endl;;
        }
    }
};


int main(){
    Graph g(4);
    g.addEdge(0,1,"e0");
    g.addEdge(0,1,"e1");
    g.addEdge(0,2,"e2");
    g.printAdjList();
    return 0;
}