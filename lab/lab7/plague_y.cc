//PASS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Graph {
    short nVertex;
    vector<short> *adjList;
    vector<vector<short> > subGraph;

public:
    Graph(short n) {
        nVertex = n;
        adjList = new vector<short>[n];
    }

    void addEdge(short v, short w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }

    vector<short> travelAll(short start, vector<bool>& visited) {
        vector<short> component;
        queue<short> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            short v = q.front();
            q.pop();
            component.push_back(v);

            for (short w : adjList[v]) {
                if (!visited[w]) {
                    visited[w] = true;
                    q.push(w);
                }
            }
        }

        return component;
    }

    void extractGraph() {
        vector<bool> visited(nVertex, false);
        vector<short> head(nVertex);
        for (short i = 0; i < nVertex; i++) {
            head[i] = i;
        }

        while (!head.empty()) {
            vector<short> component = travelAll(head[0], visited);
            if (component.size() > 1) {
                subGraph.push_back(component);
            }
            for (short node : component) {
                head.erase(remove(head.begin(), head.end(), node), head.end());
            }
        }
    }

    short bfs(short start) {
        vector<short> distance(nVertex, -1);
        queue<short> q;
        q.push(start);
        distance[start] = 0;
        short maxDist = 0;

        while (!q.empty()) {
            short v = q.front();
            q.pop();
            for (short w : adjList[v]) {
                if (distance[w] == -1) {
                    distance[w] = distance[v] + 1;
                    maxDist = max(maxDist, distance[w]);
                    q.push(w);
                }
            }
        }

        return maxDist;
    }

    short findSpread() {
        short maxSpread = 0;
        for (const auto& component : subGraph) {
            short minSpreadInComponent = nVertex;
            for (short start : component) {
                short spread = bfs(start);
                minSpreadInComponent = min(minSpreadInComponent, spread);
            }
            maxSpread = max(maxSpread, minSpreadInComponent);
        }
        return maxSpread;
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