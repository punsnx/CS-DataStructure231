#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    string line;
    vector<int> space;
    while(true){
        int minSpace = 25;
        int sumSpace = 0;
        getline(cin,line);
        n = stoi(line);
        if(n==0)break;
        for(int i = 0;i<n;i++){
            getline(cin,line);
            int spaceCount = 0;
            for(int j = 0;j<line.length();j++){
                if(line[j] == ' ')spaceCount++;
            }
            space.push_back(spaceCount);
            if(spaceCount < minSpace)minSpace = spaceCount;
        }
        for(int i = 0;i<space.size();i++){
            if(space.at(i) >= minSpace){
                // cout << space.at(i) << " - " << minSpace << endl;
                sumSpace += space.at(i) - minSpace;
            }
        }
        space.clear();
        cout << sumSpace << endl;

    }
}
