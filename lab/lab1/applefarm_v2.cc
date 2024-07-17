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
    protectArea = mana/useMana;
    if(protectArea == 0) {cout<<0<<endl;exit(0);}

    sumValue = 0;
    for(int sR = 0;sR<row;sR++){
        for(int sC = 0;sC<col;sC++){
            if(land.at(sR).at(sC) <= 0)continue;

            int n = protectArea;
            long sumTemp = 0;

            bool notfirst = false;
            for(int i = sR;i<row;i++){

                int count = 0,prev_count=0,prev_remain_n = n;
                bool notfirst_sub = false;
                cout << i << "||";
                for(int j = sC;j<col;j++){
                    // int check_odd = prev_remain_n/2.0 +1;
                    // cout << "p" << check_prev_remain_n  << "||";
                    if(n == 0)break;
                    int v = land.at(i).at(j);
                    if(n>1 && n <= prev_remain_n/2)break;
                    // if(n>1 && prev_remain_n%2 != 0 && n < check_odd)break;
                    // if(notfirst_sub && v <= 0)break;
                    // if(notfirst_sub && n < prev_count)break;
                    // if(!notfirst_sub && j+1 < col && land.at(i).at(j+1) <= 0)break;
                    // if(notfirst && j+1 < col && (land.at(i).at(j) <= 0 || land.at(i).at(j+1)))break;
                    // notfirst = true;
                    // notfirst_sub = true;
                    count++;n--;
                    sumTemp += v;
                    
                    prev_count = count;
                    cout << v << "|";
                }
                cout << endl;
            }
            if(sumTemp > sumValue) sumValue = sumTemp;
            cout << "---------------" << endl;
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
            refSum += matrix.at(m).at(n) = temp;
            cout << matrix[m][n] << "|";
        }
        cout << endl;
    }
}