#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void input(int *, int *, int, int, int, int);
void inputLandValue(vector<vector<int> > &,int ,int ,long *);
int main(){
    int row,col,mana,useMana,protectArea;
    long sumValue = 0;

    input(&col,&row,0,256,0,256);
    input(&mana,&useMana,0,1000000,1,1000000);
    vector<vector<int> > land(row,vector<int>(col,0));
    inputLandValue(land,row,col,&sumValue);
    // sumValue = sumAllMatrix
    protectArea = (mana/useMana >= row*col ? row*col : mana/useMana);
    // protectArea = mana/useMana;
    // cout << protectArea << " " << row*col << " " << sumValue <<  endl;
    if(protectArea == 0) {cout<<0<<endl;exit(0);}
    // if(protectArea >= row*col) {cout<<sumValue<<endl;exit(0);}

    sumValue = 0;
    for(int a = 1;a<=protectArea;a++){
        for(int b = protectArea;b>=1;b--){
            if(a*b<=protectArea){
                cout << " axb: "<< a*b << " | " <<  protectArea << endl;
            }
        }
    }
    cout << sumValue << endl;
    return 0;
}

void input(int *x1, int *x2, int minX1, int maxX1,int minX2,int maxX2){
    cin >> *x1 >> *x2;
    if((*x1 < minX1 || *x1 > maxX1)||(*x2 < minX2 || *x2 > maxX2)) exit(0);
}
void inputLandValue(vector<vector<int> > &matrix,int r_size,int c_size,long *refSum){

    for(int m = 0;m<r_size;m++){
        for(int n = 0;n<c_size;n++){
            int temp=0;
            cin >> temp;
            if(temp < -1000000 || temp > 1000000)exit(0);
            matrix.at(m).at(n) = temp;
            *refSum += matrix.at(m).at(n);
            // cout << matrix[m][n] << "|";
        }
        // cout << endl;
    }
}