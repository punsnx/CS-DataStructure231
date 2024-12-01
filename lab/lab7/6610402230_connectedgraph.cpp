#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int nVertex;
    vector<int> *adjList;
public:
    Graph(int n){
        nVertex = n;
        adjList = new vector<int>[n];
    }
    void addEdge(int v,int w){
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }
    void printAdjList(){
        for(int v = 0;v<nVertex;v++){
            cout << "[" << v << "] ";
            for(int w : adjList[v]){
                cout << "-> " << w << " ";
            }
            cout << "-> NULL" << endl;
        }
    }

    void DFSVisited(int s,vector<int> &adj,vector<bool> &visited){
        visited[s] = true;
        for(int &v : adj){
            if(!visited[v]){
                vector<int> &newAdj = adjList[v];
                DFSVisited(v,newAdj,visited);
            }
        }
    }
    void DFSInit(int s){
        vector<int> &adj = adjList[s];
        vector<bool> visited(nVertex,false);
        DFSVisited(s,adj,visited);
        if(count(visited.begin(),visited.end(),1) == nVertex){
            cout << "Graph is connected" << endl;
        }else{
            cout << "Graph is not connected" << endl;
        }
    }

};

int main(){

    Graph g(10);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(6,7);
    // g.addEdge(7,8);
    g.addEdge(7,9);
    g.printAdjList();
    g.DFSInit(2);
    return 0;
}
//6610402230 Sirisuk Tharntham