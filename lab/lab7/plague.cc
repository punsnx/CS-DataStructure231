#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

typedef struct _VertexInfo{
    int idx;
    int adjs;
}VertexInfo;


void bubbleSort(vector<VertexInfo> &list) {
    for(int i = 0; i < list.size() - 1; i++) {
        for(int j = 0; j < list.size() - i - 1; j++) {
            if(list[j].adjs < list[j + 1].adjs) {
                VertexInfo tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }
}

class Graph{
    int nVertex;
    int spreadTime;
    vector<int> *adjList;
    vector<VertexInfo> *vertex;
public:
    Graph(int n){
        nVertex = n;
        spreadTime = 0;
        adjList = new vector<int>[n];
        vertex = new vector<VertexInfo>(n);
        for(int i = 0;i<vertex->size();i++){
            (*vertex)[i].idx = i;
            (*vertex)[i].adjs = 0;
        }
    }
    void addEdge(int v,int w){
        adjList[v].push_back(w);
        adjList[w].push_back(v);
        (*vertex)[v].adjs++;
        (*vertex)[w].adjs++;
    }
    void sortMaxAdj(){
        bubbleSort(*vertex);
    }
    void printAdjList(){
        for(int v = 0;v<nVertex;v++){
            cout << "[" << v << "] ";
            for(int w = 0;w<adjList[v].size();w++){
                cout << "-> " << adjList[v][w] << " ";
            }
            cout << "-> NULL" << endl;
        }
    }
    void printMaxAdj(){
        for(VertexInfo v : *vertex){
            cout << v.adjs << "(" << v.idx << ")" << endl;
        }
    }
    void spreadBFS(int s,vector<bool> &visited){
        queue<int> q;

        visited[s]=true;
        q.push(s);

        while(!q.empty()){
            int v = q.front();
            q.pop();

            bool counted = false;
            for(int w : adjList[v]){
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
        for(VertexInfo v : *vertex){
            // cout << v.idx << endl;
            // cout << "-----------------" << endl;;
            spreadBFS(v.idx,visited);
            // cout << "==================" << endl;
            if(spreadTime < minSpread && spreadTime > 0)minSpread = spreadTime;
            spreadTime = 0;
        }
        cout << "SpreadTIME : " << (minSpread == 2147483647 ? 0 : minSpread) << endl;
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
    g.sortMaxAdj();
    int m = T * g.findSpread();
    // g.printMaxAdj();
    int h = m / 60;
    m = m % 60;
    int day = h / 24;
    h = h%24;
    int month = day / 30;
    day = day % 30;
    int year = month / 12;
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
