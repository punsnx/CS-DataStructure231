#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

class Graph{
    short nVertex;
    short spreadTime;
    vector<short> *adjList;
    int maxAdj = 0;
    int maxAdjIdx = 0;
public:
    Graph(short n){
        nVertex = n;
        spreadTime = 0;
        adjList = new vector<short>[n];
    }
    void addEdge(short v,short w){
        adjList[v].push_back(w);
        adjList[w].push_back(v);
        if(adjList[v].size() > maxAdj){
            maxAdj = adjList[v].size();
            maxAdjIdx = v;
        }
        if(adjList[w].size() > maxAdj){
            maxAdj = adjList[w].size();
            maxAdjIdx = w;
        }

    }
    void printAdjList(){
        for(short v = 0;v<nVertex;v++){
            cout << "[" << v << "] ";
            for(short w = 0;w<adjList[v].size();w++){
                cout << "-> " << adjList[v][w] << " ";
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

            bool counted = false;
            for(short w : adjList[v]){
                if(!visited[w]){
                    visited[w] = true;
                    q.push(w);
                    if(!counted){
                        // cout << w << endl;
                        counted = true;
                        spreadTime++;
                    }
                }
            }
        }

    }
    int findSpread(){
        int minSpread = 2147483647;
        vector<bool> visited(nVertex,false);

        spreadBFS(maxAdjIdx, visited);
        if (spreadTime < minSpread && spreadTime > 0) {
            minSpread = spreadTime;
        }
        spreadTime = 0;

        for (short v = 0; v < nVertex; ++v) {
            vector<bool> visited(nVertex,false);
            if(v != maxAdjIdx){
                spreadBFS(v, visited);
                if (spreadTime < minSpread && spreadTime > 0) {
                    minSpread = spreadTime;
                }
                spreadTime = 0;
            }
        }
        return (minSpread == 2147483647 ? 0 : minSpread);
        

    }
};

int main(){
    string line;
    int N,T;
    getline(cin,line);
    N = stoi(line);
    getline(cin,line);
    T = stoi(line);

    Graph g(N);

    while(getline(cin,line)){
        if(line == "-1")break;
        istringstream in(line);
        string tmp;
        int pI,pJ;
        getline(in,tmp, ' ');
        pI = stoi(tmp);
        getline(in,tmp, ' ');
        pJ = stoi(tmp);

        g.addEdge(pI,pJ);
    }
    // g.printAdjList();
    // g.sortMaxAdj();
    long m = T * g.findSpread();
    // g.printMaxAdj();
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
