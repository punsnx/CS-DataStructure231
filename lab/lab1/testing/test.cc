#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

void input(int *, int *, int, int, int, int);
void inputLandValue(vector<vector<int> > &,int ,int ,long *);
void findShape(vector<vector<int> > &,int ,int ,int ,int ,int ,long *);
int main(){
    int row,col,mana,useMana,protectArea;
    long sumValue = 0;

    input(&col,&row,0,256,0,256);
    input(&mana,&useMana,0,1000000,1,1000000);
    vector<vector<int> > land(row,vector<int>(col,0));
    inputLandValue(land,row,col,&sumValue);

    protectArea = (mana/useMana >= row*col ? row*col : mana/useMana);
    if(protectArea == 0) {cout<<0<<endl;exit(0);}

    sumValue = 0;

    int temp = 0;
    if(protectArea==1){
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                temp += land.at(i).at(j);
            }
        }
        if(temp > sumValue) sumValue = temp;
    }

    // Factorization
    int n=protectArea;short exponent;
    // if(n < 2 || n > INT_MAX) return 0;
    int d = 2;
    while(n>1){
        exponent = 0;
        if(d>(n/d)){
            ++exponent;
            findShape(land,protectArea,n,exponent,row,col,&sumValue);
            break;
        }
        if(n % d == 0){
            while(n%d==0){
                ++exponent;
                n/=d;
            }
            findShape(land,protectArea,d,exponent,row,col,&sumValue);
        }
        if(d==2) ++d;
        else d+=2;
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

void findShape(vector<vector<int> > &arr,int pArea,int eachFactor,int exponent,int row,int col,long *max){
    // cout << pArea << " " << eachFactor << " " << exponent << endl;
    int maxFactor = pow(eachFactor,exponent);

    for(int rS = 0;rS < row;rS++){
        for(int cS = 0;cS < col;cS++){

            int subRow = row-rS;
            int subCol = col-cS;
            for(int n = eachFactor;n<=maxFactor;n*=eachFactor){
                // cout << "- : " << n << endl;
                for(int m = 1;m<=pArea;m++){  

                    if(((n<=subRow && m<=subCol) || (m<=subRow && n<=subCol)) && pArea % m == 0 && n*m <= pArea){
                        // cout << "n*m : " << n << "*" << m << " = " <<n*m << endl;
                        long temp;int r_size,c_size;
                        // n row m col
                        r_size = (n <= subRow ? n : subRow);
                        c_size = (m <= subCol ? m : subCol);
                        
                        temp = 0;
                        for(int i = rS;i<rS+r_size;i++){
                            for(int j = cS;j<cS+c_size;j++){
                                temp += arr.at(i).at(j);
                            }
                        }
                        if(temp > *max) *max = temp;
                        // m row n col
                        r_size = (m <= subRow ? m : subRow);
                        c_size = (n <= subCol ? n : subCol);
                        
                        temp = 0;
                        for(int i = rS;i<rS+r_size;i++){
                            for(int j = cS;j<cS+c_size;j++){
                                temp += arr.at(i).at(j);
                            }
                        }
                        if(temp > *max) *max = temp;
                        

                        
                    }

                }
            }




        }
    }
    

}