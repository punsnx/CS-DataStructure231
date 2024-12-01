#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef struct _Vertex{
    int number;
    vector<int> adj;
}Vertex;


class Graph{
    string type;
    int nVertex;
    vector<Vertex> adjList;
public:
    Graph(int v,string type){
        this->type = type;
        nVertex = v;
        adjList = vector<Vertex>(v);
        if(type == "Matrix"){//Adj Matrix
            for(int i = 0;i<v;i++){
                adjList[i].number = i;
                adjList[i].adj = vector<int>(v);
                fill(adjList[i].adj.begin(),adjList[i].adj.end(),0);
            }
        }else{//Adj List
            for(int i = 0;i<v;i++){
                adjList[i].number = i;
            }
        }
    }
    int getRealIdx(int idx){//prevent delete index
        for(int i = 0;i<nVertex;i++){
            if(adjList[i].number == idx){
                return i;
            }
        }
        return -1;
    }
    void addEdge(int v,int w){
        //prevent delete index
        int V = getRealIdx(v);
        int W = getRealIdx(w);
        if(V < 0 || W < 0)return;

        vector<int> &adj = adjList[V].adj;
        if(type == "Matrix"){
            adj[W] = 1;
        }else{
            adj.push_back(w);
        }
    }
    void removeEdge(int v,int w){
        //prevent delete index
        int V = getRealIdx(v);
        int W = getRealIdx(w);
        if(V < 0 || W < 0)return;

        vector<int> &adj = adjList[V].adj;
        if(type == "Matrix"){
            adj[W] = 0;
        }else{
            for(int i = 0;i < adj.size();i++){
                if(adj[i] == w){
                    adj.erase(adj.begin() + i);
                    return;
                }
            }
        }
    }
    void removeVertex(int vertex){
       //prevent delete index
        int V = getRealIdx(vertex);
        if(V < 0 )return;
        
        if(type == "Matrix"){
            for(int v = 0;v < nVertex;v++){
                vector<int> &adj = adjList[v].adj;
                adj.erase(adj.begin() + V);
            }
        }else{
            for(int v = 0;v < nVertex;v++){
                vector<int> &adj = adjList[v].adj;
                for(int e = 0;e<adj.size();e++){
                    if(adj[e] == vertex){
                        adj.erase(adj.begin() + e);
                        break;
                    }
                }
                
            }
        }
        adjList.erase(adjList.begin() + V);
        nVertex--;
    }
    void addVertex(){
        int last;
        if(adjList.size() > 0){
            last = adjList.back().number;
        }else{
            last = -1;
        }
        Vertex newVertext;
        newVertext.number = last+1;
        if(type=="Matrix"){
            for(int v = 0;v<nVertex;v++){
                adjList[v].adj.push_back(0);
            }
            newVertext.adj = vector<int>(adjList.size()+1);
        }
        adjList.push_back(newVertext);

        if(type == "Matrix"){//INIT MATRIX ZERO
            vector<int> &adj = adjList.back().adj;
            fill(adj.begin(),adj.end(),0);
        }//FOR LIST LEAVE DEFAULT

        nVertex++;
    }
    int getInDegree(int vertex){

        int count = 0;
        if(type=="Matrix"){
            //prevent delete index
            int W = getRealIdx(vertex);
            if(W < 0 )return 0;

            for(int v = 0;v<nVertex;v++){
                vector<int> &adj = adjList[v].adj;
                if(adj[W] == 1)count++;
            }
            return count;
        }else{
            for(int v = 0;v<nVertex;v++){
                vector<int> &adj = adjList[v].adj;
                for(int w = 0;w<adj.size();w++){
                    if(adj[w] == vertex)count++;
                }
            }
            return count;
        }

    }
    int getOutDegree(int vertex){
        //prevent delete index
        int V = getRealIdx(vertex);
        if(V < 0 )return 0;

        vector<int> &adj = adjList[V].adj;
        if(type=="Matrix"){
            int count = 0;
            for(int w = 0;w<adj.size();w++){
                if(adj[w] == 1)count++;
            }
            return count;
        }else{
            return adj.size();
        }
    }
    void printMaxInDegree(){
        int maxVertex = -1;
        int maxVertexInDegree = -1;
        for(int v = 0;v<nVertex;v++){
            int vertex = adjList[v].number;
            int inDegree = getInDegree(vertex);
            if(inDegree > maxVertexInDegree){
                maxVertex = vertex;
                maxVertexInDegree = inDegree;
            }
        }
        cout << "Maximum In-Degree  : Vertex " << maxVertex << " " << maxVertexInDegree << endl; 
    }
    void printMaxOutDegree(){
        int maxVertex = -1;
        int maxVertexOutDegree = -1;
        for(int v = 0;v<nVertex;v++){
            int vertex = adjList[v].number;
            int outDegree = getOutDegree(vertex);
            if(outDegree > maxVertexOutDegree){
                maxVertex = vertex;
                maxVertexOutDegree = outDegree;
            }
        }
        cout << "Maximum Out-Degree : Vertex " << maxVertex << " " << maxVertexOutDegree << endl; 
    }

    void printAdjList(){
        if(type == "Matrix"){
            cout << "  ";
            for(int v = 0;v < nVertex;v++){
                cout << adjList[v].number << " ";
            }
            cout << endl;
        }
        for(int v = 0;v < nVertex;v++){
            vector<int> &adj = adjList[v].adj;
            size_t edgeSize = adj.size();
            if(type == "Matrix"){
                cout << adjList[v].number << " ";
                for(int e = 0;e<edgeSize;e++){
                    cout << adj[e] << " ";
                }
            }else{
                cout << "[" << adjList[v].number << "] ";
                for(int e = 0;e< edgeSize;e++){
                    cout << "-> " << adj[e] << " ";
                }
                cout << "-> NULL";
            }
            cout << endl;
        }
        cout << "====================" << endl;
    }

};
int main(){
    string type;
    int nInitVertex;

    string line;
    string input;

    getline(cin,line);
    istringstream in(line);
    getline(in,type,' ');
    getline(in,input,' ');
    nInitVertex = stoi(input);
    
    Graph g(nInitVertex,type);

    while(getline(cin,line)){
        istringstream in(line);
        getline(in,input,' ');

        int a,b;
        if(input[0] == 'e'){//add edge a b
            getline(in,input,' ');
            a = stoi(input);
            getline(in,input,' ');
            b = stoi(input);
            g.addEdge(a,b);

        }else if(input[0] == 'r'){//remove edge a b
            getline(in,input,' ');
            a = stoi(input);
            getline(in,input,' ');
            b = stoi(input);
            g.removeEdge(a,b);

        }else if(input[0] == 'v'){//add vertex
            g.addVertex();
            
        }else if(input[0] == 'u'){//remove vertex
            getline(in,input,' ');
            a = stoi(input);
            g.removeVertex(a);
            
        }else if(input[0] == 'p'){//print graph
            g.printAdjList();
        }else if(input[0] == 'q'){
            g.printMaxInDegree();
            g.printMaxOutDegree();
            return 0;
        }else{
            return 0;
        }


    }

}
