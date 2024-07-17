#include <iostream>
#include <climits>
using namespace std;

void getLandValue(int **,int ,int ,long long int *);
void findProtected(int**,int,int,int);
int main(){
    int a,b,n,m;
    long long int sumLandValue = 0;
    cin >> b >> a;
    cin >> n >> m;
    int **land = new int*[a];
    for(int i = 0;i<a;i++){
        land[i] = new int[b];
    }
    // cout << "axb: " << a << "x" << b << endl;
    getLandValue(land,a,b,&sumLandValue);
    // if(a == 0 || b == 0){cout << 0 << endl;exit(0);}
    int n_protected = n/m;
    if(n_protected == 0){cout << 0 << endl;exit(0);}
    if(n_protected >= a*b){cout << sumLandValue << endl;exit(0);}
    findProtected(land,a,b,n_protected);
    return 0;
}
void getLandValue(int **arr,int a,int b,long long int *sumV){
    for(int r = 0;r<a;r++){
        for(int c = 0;c<b;c++){
            cin >> arr[r][c];
            *sumV += arr[r][c];
            // cout << arr[r][c] << "|";
        }
        // cout << endl;
    }
}

void findProtected(int** arr,int row,int col,int n){
    long long int max = LLONG_MIN;
    for(int r = 0;r<row;r++){
        for(int c = 0;c<col;c++){

            for(int a = 1; a <= row-r;a++){
                for(int b = 1; b <= col-c;b++){
                    if(a*b == n || a*b < n){
                    // cout << "axb: " << a << "x" << b << "=" << a*b << endl;

                        long long int temp = 0;
                        for(int i = r;i<r+a;i++){
                            for(int j = c;j<c+b;j++){
                                // cout << arr[i][j] << "|";
                                temp += arr[i][j];
                            }
                            // cout << endl;
                        }
                        if(temp > max) max = temp;
                        // cout << endl;
                    }
                   
                }
            }
        }
    }
    cout << max << endl;
}
