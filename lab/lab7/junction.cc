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
            cout << v+1;
            size_t edgeSize = adjList[v].size();
            for(int e = 0;e < edgeSize ;e++){
                cout << "->" << adjList[v][e].edge << "(" << adjList[v][e].vertex+1 << ")";
            }
            cout << "->NULL" << endl;;
        }
    }
    void printConnectionType(){
        for(int v = 0;v < this->nVertex;v++){
            int edgeSize = adjList[v].size();
            string type;
            if(edgeSize > 2)type = "Junction of ";
            else if(edgeSize == 2)type = "Corner connecting ";
            else if(edgeSize == 1)type = "Impasse coming from ";
            else type = "Isolated";
            cout << "v" << v+1 << ": " << type;

            for(int e = 0;e < edgeSize ;e++){
                cout << adjList[v][e].edge << " ";
            }
            cout << endl;;
        }
    }
};


int main(){
    int v,e;
    cin >> v >> e;
    Graph g(v);
    for(int i = 0;i<e;i++){
        int vA,vB;
        string edge = "e" + to_string(i+1);
        cin >> vA >> vB;
        g.addEdge(vA-1,vB-1,edge);
    }
    // g.printAdjList();
    g.printConnectionType();

    return 0;
}