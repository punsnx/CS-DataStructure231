#include <iostream>
using namespace std;

void getLandValue(int *arr,int b){
    short int i=0;
    int inValue;
    while(i<b){
        cin >> inValue;
        if(inValue<-1000000 || inValue>1000000) continue;
        arr[i] = inValue;
        cout << arr[i] << "|";
        ++i;
    }
    cout << endl;
}
long int sumProtectedValue(int **arr,short int a,short int b,short int n){
    short int h=0,i,j,curMax_i=0,curMax_j=0;
    long int value=0;
    int max;
    while(h<n){
        max = -2147483648;
        i=0;
        while(i<a){
            j=0;
            while(j<b){
                if(arr[i][j] > max){
                    
                    max = arr[i][j];
                    curMax_i = i;
                    curMax_j = j;
                }
                ++j;
            }
            ++i;
        }
        value += max;
        arr[curMax_i][curMax_j] = -2147483648;
        ++h;
    }
    return value;
}
int main(){
    short int a,b,i;
    int n,m;
    cin >> b >> a;
    if((a<0 || a>256)||(b<0 || b>256))return 0;
    cin >> n >> m;
    if((n<0 || n>1000000)||(m<1 || m>1000000))return 0;
    if(a == 0 || b == 0){
        cout << 0;
        return 0;
    }

    int **land = new int*[a];
    for(i=0;i<a;i++){
        land[i] = new int[b];
    }
    i=0;
    while(i<a){
        getLandValue(land[i],b);
        ++i;
    }
    short int nProtected = n/m;
    cout << sumProtectedValue(land,a,b,nProtected) << endl;
    return 0;



}