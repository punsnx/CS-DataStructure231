#include <iostream>
#include <climits>
using namespace std;

int main(){
    short m;
    cin >> m;
    string name[m];
    int stats[m][3];
    long eval[m];
    long min=LONG_MAX,max=LONG_MIN;
    short minIndex,maxIndex;
    for(short i = 0;i<m;i++){
        cin >> name[i];
        for(short j = 0;j<3;j++){
            cin >> stats[i][j];
        }
        eval[i] = stats[i][0] + (stats[i][1]*stats[i][2]);
        if(eval[i] > max){max =eval[i];maxIndex=i;}
        if(eval[i] < min){min =eval[i];minIndex=i;}
    }
    for(short i = 0;i<m;i++){
        cout << name[i] << ": (HP " << stats[i][0] << " | " << stats[i][1] << "/" << stats[i][2] << ") - EVAL " << eval[i] << endl;
    }
    cout << "The weakest monster is " << name[minIndex] << " with evaluation of " << eval[minIndex] << endl;
    cout << "The strongest monster is " << name[maxIndex] << " with evaluation of " << eval[maxIndex] << endl;

}