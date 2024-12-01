#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


void sumLightSource(vector<vector<vector<int> > > &cube,int n,int X,int Y,int Z,int L){
    // vector<vector<vector<int> > > tempCube(n, vector<vector<int> >(n, vector<int>(n, 0)));
    
    for(int x = 0;x < n;x++){
        for(int y = 0;y < n;y++){
            for(int z = 0;z < n;z++){
                if(x == X && y == Y && z == Z){
                    cube[x][y][z] += L;
                }else{
                    int distance = sqrt(pow(X - x, 2) + pow(Y - y, 2) + pow(Z - z, 2));
                    int l = (L - distance <= 0 ? 0 : L - distance);
                    // cout << x << " " << y << " " << z << " D " << distance << " l " << l << endl;
                    cube[x][y][z] += l;
                }
            }
        }
    }
    cout << endl;

}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    if(n == 0)return 0;
    vector<vector<vector<int> > > cube(n, vector<vector<int> >(n, vector<int>(n, 0)));

    // int t = (n/2 < 1 ? 1 : n/2);
    string line;
    while(getline(cin,line)){
        // cout << line << endl;;
        istringstream in(line);
        int x,y,z,l;
        for(int j = 0;j<4;j++){
            in >> x >> y >> z >>l;
        }
        sumLightSource(cube,n,x,y,z,l);
    }

    for(int x = 0;x < n;x++){
        for(int y = 0;y < n;y++){
            // cout << "(" << y << ")";
            for(int z = 0;z < n;z++){
                cout << cube[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }



}

