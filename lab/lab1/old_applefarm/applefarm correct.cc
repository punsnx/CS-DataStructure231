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
void findRatio(int **arr,short int a, short int b, int n);
long int sumLandValue(int **arr,short int a,short int b);
long int findMostValueLand(int **arr,short int a,short int b,short int r, short int c);
int main(){
    // init
    short int a,b,i;
    int n,m;
    // input row and col
    cin >> b >> a;
    if((a<0 || a>256)||(b<0 || b>256))return 0;
    // input mana and mana use value
    cin >> n >> m;
    if((n<0 || n>1000000)||(m<1 || m>1000000))return 0;
    // check area 
    if(a == 0 || b == 0){
        cout << 0;
        return 0;
    }
    // create array of land
    int **land = new int*[a];
    for(i=0;i<a;i++){
        land[i] = new int[b];
    }
    // input land vallue
    i=0;
    while(i<a){
        getLandValue(land[i],b);
        ++i;
    }
    int nProtected = n/m;
    // cout << sumProtectedValue(land,a,b,nProtected) << endl;
    if(nProtected >= a*b){
        cout << sumLandValue(land,a,b) << endl;
        return 0;
    }

    findRatio(land,a,b,nProtected);
    return 0;



}

void findRatio(int **arr,short int a, short int b, int n){
    cout << a << " " << b << " " << n << endl;
    short int row=1,col=1;
    long int ratioSumMax=0,allRatioMax = -2147483648;
    while(row<a+1){
        col=1;
        while(col<b+1){
            if(row*col<=n){
                cout << "rxc: " << row << " x " << col << " = " << row*col << endl;
                ratioSumMax = findMostValueLand(arr,a,b,row,col);
                if(ratioSumMax > allRatioMax) allRatioMax = ratioSumMax;
            }
            ++col;
        }
        ++row;
    }
    cout << "all ratio max: " << allRatioMax << endl;
}
long int sumLandValue(int **arr,short int a,short int b){
    short int r=0,c=0;
    long int sumValue=0;
    while(r<a){
        c=0;
        while(c<b){
            sumValue += arr[r][c];
            ++c;
        }
        ++r;
    }
    return sumValue;
}

long int findMostValueLand(int **arr,short int a,short int b,short int r, short int c){
    //row, col observe final and traversal;
    short int ro,co,rf,cf,rt,ct;
    long int sumValue,maxRatioSumV=-2147483648;
    ro = 0;
    rt = a - r + 1;
    while(ro<rt){
        
        rf = (ro + r) - 1;

        cout << "rO-rF: " << ro << " - " << rf << endl;
    
        co=0;
        ct = b - c + 1;
        while(co<ct){
            sumValue=0;
            cf = (co + c) - 1;
            cout << "cO-cF: " << co << " - " << cf << endl;
            for(short int i = ro;i<rf+1;i++){
                
                for(short int j = co;j<cf+1;j++){
                    // cout << j << " ";
                    cout << arr[i][j] << "|";

                    sumValue += arr[i][j];

                }
                cout << endl;
            }
            cout << endl;
            if(sumValue > maxRatioSumV){
                maxRatioSumV = sumValue;
            }
            ++co;
            
        }
        // cout << endl;
        ++ro;
    }
    // cout << endl;
    cout << "[" << r << "x" << c << "] sum: " << maxRatioSumV << endl;
    return maxRatioSumV;

}