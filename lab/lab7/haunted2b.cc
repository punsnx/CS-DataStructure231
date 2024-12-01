//CORRECT!!!!!!!
//6610402230 Sirisuk Tharntham
//Solve maze by BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct _Vertex{
    int number;
    vector<int> adj;
}Vertex;

class Graph{
    int nVertex;
    int endNumber;
    bool isEscapeable;
    vector<Vertex> adjList;
public:
    Graph(int endNumber){
        nVertex = 0;
        adjList = vector<Vertex>(0);
        this->endNumber = endNumber;
        isEscapeable = false;
    }
    void addVertex(int number){
        Vertex newVertex = {number};
        adjList.push_back(newVertex);
        nVertex++;
    }
    void addEdge(int v,int w){
        adjList[v].adj.push_back(w);
        adjList[w].adj.push_back(v);
    }
    void printAdjList(){
        for(int v = 0;v<nVertex;v++){
            cout << "[" << v << "] ";
            for(int w = 0;w<adjList[v].adj.size();w++){
                cout << "-> " << adjList[v].adj[w] << " ";
            }
            cout << "-> NULL" << endl;
        }
    }
    void BFS(int s){
        vector<bool> visited(nVertex, false);
        queue<int> q;

        visited[s] = true;
        q.push(s);

        while(!q.empty()){
            int v = q.front();
            q.pop();

            if(adjList[v].number == endNumber){
                isEscapeable = true;
                break;
            }

            for(int w : adjList[v].adj){
                if(!visited[w]){
                    visited[w] = true;
                    q.push(w);
                }
            }
        }

        if(isEscapeable){
            cout << "Yeah, There's The Way Out!" << endl;
        }else{
            cout << "Oh No! We're Trapped." << endl;
        }
    }
};

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> prev,cur;
    int S,E,P;
    cin >> S >> E;
    cin >> P;

    Graph g(E);
    int vIdx = -1;
    int startIdx;
    for(int n = 0;n<N;n++){
        cur.clear();
        for(int m = 0;m<M;m++){
            int number;
            cin >> number;
            g.addVertex(number);
            cur.push_back(number);
            vIdx++;
            
            if(number == S){
                startIdx = vIdx;
            }
            if(number == S || number == E || number == P){
                if(n == 0){
                    if(m > 0){
                        if(cur[m-1] == S || cur[m-1] == E || cur[m-1] == P){
                            g.addEdge(vIdx,vIdx-1);
                        }
                    }
                }else{
                    if(m == 0){
                        if(prev[m] == S || prev[m] == E || prev[m] == P){
                            g.addEdge(vIdx,vIdx-M);
                        }
                    }else{
                        if(prev[m] == S || prev[m] == E || prev[m] == P){
                            g.addEdge(vIdx,vIdx-M);
                        }
                        if(cur[m-1] == S || cur[m-1] == E || cur[m-1] == P){
                            g.addEdge(vIdx,vIdx-1);
                        }
                    }

                }
            }
           
        }
        prev = cur;
       
    }
    // g.printAdjList();
    // cout << "===========" << endl;
    g.BFS(startIdx);

    return 0;
}