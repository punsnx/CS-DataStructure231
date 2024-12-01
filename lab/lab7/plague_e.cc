#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

typedef struct _Edge{
    short vertex;
    _Edge *next;
}Edge;

typedef struct _Vertex{
    Edge *adj;
}Vertex;

class Graph{
    short nVertex;
    short spreadTime;
    Vertex *adjList;
public:
    Graph(short n){
        nVertex = n;
        spreadTime = 0;
        adjList = new Vertex[n];
        for(int v = 0;v<n;v++){
            adjList[v].adj = NULL;
        }
    }
    void addEdge(short v,short w){
        Edge *newEdgeW = new Edge;
        newEdgeW->vertex = w;
        newEdgeW->next = NULL;
        Edge *newEdgeV = new Edge;
        newEdgeV->vertex = v;
        newEdgeV->next = NULL;
        Edge *cur = NULL;
        if(adjList[v].adj == NULL){
            adjList[v].adj = newEdgeW;
        }else{
            cur = adjList[v].adj;
            while(cur && cur->next){
                cur = cur->next;
            }
            cur->next = newEdgeW;
        }
        if(adjList[w].adj == NULL){
            adjList[w].adj = newEdgeV;
        }else{
            cur = adjList[w].adj;
            while(cur && cur->next){
                cur = cur->next;
            }
            cur->next = newEdgeV;
        }

    }
    void printAdjList(){
        for(short v = 0;v<nVertex;v++){
            cout << "[" << v << "] ";
            Edge *cur = adjList[v].adj;
            while(cur){
                cout << "-> " << cur->vertex << " ";
                cur = cur->next;
            }    
            cout << "-> NULL" << endl;
        }
    }
    void spreadBFS(short s,vector<bool> &visited){
        queue<short> q;

        visited[s]=true;
        q.push(s);

        while(!q.empty()){
            short v = q.front();
            q.pop();

            cout << v << " ";
            bool counted = false;
            Edge *curAdj = adjList[v].adj;
            while(curAdj){
                short &w = curAdj->vertex;
                if(!visited[w]){
                    visited[w] = true;
                    q.push(w);
                    if(!counted){
                        // cout << w << endl;
                        counted = true;
                        spreadTime++;
                    }
                }
                curAdj = curAdj->next;
            }
        }

    }
    short findSpread(){
        short minSpread = nVertex-1;
    
        for (short i = 0; i < nVertex; ++i) {
            vector<bool> visited(nVertex,false);
            for (short v = 0; v < nVertex; ++v) {
                short startV = (i+v) % nVertex;
                // short startV = v;
                spreadBFS(startV, visited);
                if (spreadTime < minSpread && spreadTime > 0) {
                    minSpread = spreadTime;
                }
                spreadTime = 0;
                cout << endl;
            }
            cout << "================" <<endl;
        }
        return (minSpread == nVertex-1 ? 0 : minSpread);
        

    }
};

int main(){
    string line;
    short N;int T;
    getline(cin,line);
    N = stoi(line);
    getline(cin,line);
    T = stoi(line);

    Graph g(N);

    while(getline(cin,line)){
        if(line == "-1")break;
        istringstream in(line);
        string tmp;
        short pI,pJ;
        getline(in,tmp, ' ');
        pI = stoi(tmp);
        getline(in,tmp, ' ');
        pJ = stoi(tmp);

        g.addEdge(pI,pJ);
    }
    // g.printAdjList();
    unsigned long m = T * g.findSpread();
    long h = m / 60;
    m = m % 60;
    long day = h / 24;
    h = h%24;
    long month = day / 30;
    day = day % 30;
    long year = month / 12;
    month = month % 12;
    
    if(year > 0){
        cout << year << " ";
    }
    if(year == 1)cout << "year ";
    if(year > 1)cout << "years ";

    if(month > 0){
        cout << month << " ";
    }
    if(month == 1)cout << "month ";
    if(month > 1)cout << "months ";

    if(day > 0){
        cout << day << " ";
    }
    if(day == 1)cout << "day ";
    if(day > 1)cout << "days ";

    if(h > 0){
        cout << h << " ";
    }
    if(h == 1)cout << "hour ";
    if(h > 1)cout << "hours ";

    cout << m << " ";
    if(year == 1)cout << "minute ";
    if(year > 1 || year == 0)cout << "minutes ";
    cout << endl;

}
