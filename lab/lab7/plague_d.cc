#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

class Graph{
    short nVertex;
    short spreadTime;
    bool **adjList;
public:
    Graph(short n){
        nVertex = n;
        spreadTime = 0;
        adjList = new bool*[n];
        for(int v = 0;v<n;v++){
            adjList[v] = new bool[n]();
        }
    }
    void addEdge(short v,short w){
        adjList[v][w] = true;
        adjList[w][v] = true;
    }
    void printAdjList(){
        for(short v = 0;v<nVertex;v++){
            cout << "[" << v << "] ";
            for(short w = 0;w<nVertex;w++){
                if(adjList[v][w] == true){
                    cout << "-> " << w << " ";
                }
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
            for(short w = 0;w<nVertex;w++){
                if(adjList[v][w] == true && !visited[w]){
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
    short findSpread(){
        short minSpread = nVertex-1;
    
        for (short i = 0; i < nVertex; ++i) {
            vector<bool> visited(nVertex,false);
            for (short v = 0; v < nVertex; ++v) {
                short startV = (i+v) % nVertex;
                spreadBFS(startV, visited);
                if (spreadTime < minSpread && spreadTime > 0) {
                    minSpread = spreadTime;
                }
                spreadTime = 0;
            }
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
