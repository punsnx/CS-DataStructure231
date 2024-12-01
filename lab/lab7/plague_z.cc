#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Graph{
    short nVertex;
    vector<short> *adjList;
    vector<vector<short> > subGraph;
    short spreadTime;
public:
    Graph(short n){
        nVertex = n;
        adjList = new vector<short>[n];
    }
    void addEdge(short v,short w){
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }
    void addSubGraph(queue<short> &sub){
        vector<short> newSubGraph(sub.size());
        short i = 0;
        while(!sub.empty()){
            newSubGraph[i] = sub.front();
            sub.pop();
            ++i;
        }
        subGraph.push_back(newSubGraph);
    }
    void extractGraph(){
        //BFS Extract
        vector<bool> visited(nVertex,false);
        for(short s = 0;s<nVertex;s++){
            visited[s] = true;
            queue<short> q;

            q.push(s);
            queue<short> sub;
            while(!q.empty()){
                short v = q.front();
                q.pop();
                
                sub.push(v);
                for(short &w : adjList[v]){
                    if(!visited[w]){
                        // cout << w << " ";
                        visited[w] = true;
                        q.push(w);
                    }
                }
            }
            if(sub.size() > 1)addSubGraph(sub);
        }
    }
    void printAdjList(){
        for(short v = 0;v < nVertex;++v){
            cout << "[" << v << "] ";
            for(short w = 0;w < adjList[v].size();++w){
                cout << "-> " << adjList[v][w] << " ";
            }
            cout << "-> NULL" << endl;
        }
    }
    void printSubGraph(){
        for(short i = 0;i < subGraph.size(); ++i){
            cout << "Sub[" << i << "] ";
            for(short j = 0;j < subGraph[i].size();++j){
                cout << subGraph[i][j] << " ";
            }
            cout << endl;
        }
    }
    void BFS(short s,vector<bool> &visited){
            visited[s] = true;
            queue<short> q;
            q.push(s);

            while(!q.empty()){
                short v = q.front();
                q.pop();

                bool counted = false;
                for(short &w : adjList[v]){
                    if(!visited[w]){
                        visited[w] = true;
                        q.push(w);
                        if(counted == false){
                            spreadTime++;
                            counted = true;
                        }
                    }
                }
            }
    }
    short findSpread(){
        short minSpreadAll = 0;
        vector<short> minSpreadSub(subGraph.size(),nVertex-1);
        for(short sub = 0;sub < subGraph.size(); ++sub){
            for(short s = 0;s < subGraph[sub].size(); ++s){
                vector<bool> visited(nVertex,false);
                spreadTime = 0;
                BFS(subGraph[sub][s],visited);
                if(spreadTime < minSpreadSub[sub])minSpreadSub[sub] = spreadTime;
            }
            // cout << "Sub[" << sub << "] " << minSpreadSub[sub] << " ";
            if(minSpreadSub[sub] > minSpreadAll)minSpreadAll = minSpreadSub[sub];
        }
        // cout << endl;
        // cout << minSpreadAll << endl;
        return minSpreadAll;
    }
};

int main(){
    int n, minutes;
    cin >> n >> minutes;
    Graph g(n);

    int a, b;
    while ((cin >> a) && (a != -1)) {
        cin >> b;
        g.addEdge(a,b);
    }

    g.extractGraph();
    // g.printAdjList();
    // g.printSubGraph();
    unsigned long m = minutes * g.findSpread();
    long h = m / 60;
    m = m % 60;
    long day = h / 24;
    h = h%24;
    long month = day / 30;
    day = day % 30;
    long year = month / 12;
    month = month % 12;
    
    if(year > 0){
        cout << year << " year" << (year > 1 ? "s " : " ");
    }
    if(month > 0){
        cout << month << " month" << (month > 1 ? "s " : " ");
    }
    if(day > 0){
        cout << day << " day" << (day > 1 ? "s " : " ");
    }
    if(h > 0){
        cout << h << " hour" << (h > 1 ? "s " : " ");
    }
    if(m > 0){
        cout << m << " minute" << (m > 1 ? "s" : "");
    }
    if(year == 0 && month == 0 && day == 0 && h == 0 && m == 0){
        cout << 0 << " minutes";
    }
    cout << endl;
    return 0;
}
