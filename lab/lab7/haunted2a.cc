//DFS MATRIX CORRECT
#include <iostream>
#include <vector>
using namespace std;

bool isValid(const vector<vector<int> > &matrix, vector<vector<bool> > &visited, int r, int c, int P, int E) {
    int N = matrix.size(), M = matrix[0].size();
    return r >= 0 && r < N && c >= 0 && c < M && !visited[r][c] && (matrix[r][c] == P || matrix[r][c] == E);
}

bool DFSVisit(vector<vector<int> > &matrix,vector<vector<bool> > &visited,int E,int P,int sN,int sM){
    if(matrix[sN][sM] == E){
        return true;
    }
    visited[sN][sM] = true;
    int r[] = {-1,1,0,0};
    int c[] = {0,0,-1,1};
    for(int i = 0;i<4;i++){
        int sNNew = sN + r[i];
        int sMNew = sM + c[i];
        if(isValid(matrix,visited,sNNew,sMNew,P,E)){
            if(DFSVisit(matrix,visited,E,P,sNNew,sMNew))return true;
        }
    }
    return false;

}

int main(){
    int N,M;
    cin >> N >> M;
    int S,E,P;
    cin >> S >> E;
    cin >> P;

    int sN,sM,eN,eM;
    vector<vector<int> > matrix(N,vector<int>(M));
    vector<vector<bool> > visited(N,vector<bool>(M,false));
    for(int n = 0;n<N;n++){
        for(int m = 0;m<M;m++){
            cin >> matrix[n][m];
            if(matrix[n][m] == S){
                sN = n;
                sM = m;
            }
        }
    }

    if(DFSVisit(matrix,visited,E,P,sN,sM)){
        cout << "Yeah, There's The Way Out!" << endl;
    }else{
        cout << "Oh No! We're Trapped." << endl;
    }


}
