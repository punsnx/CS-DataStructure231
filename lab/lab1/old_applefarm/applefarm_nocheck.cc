#include <iostream>
#include <limits.h>
using namespace std;

void getLandValue(int *arr,int b){
    short int i=0;
    int inValue;
    while(i<b){
        cin >> inValue;
        arr[i] = inValue;
        ++i;
    }
}
void findRatio(int **arr,short int a, short int b, int n);
long long int sumLandValue(int **arr,short int a,short int b);
long long int findMostValueLand(int **arr,short int a,short int b,short int r, short int c);
int lastFactor(short int n);

int main(){
    short int a,b,i;
    int n,m;
    cin >> b >> a;
    cin >> n >> m;
    
    int **land = new int*[a];
    for(i=0;i<a;i++){
        land[i] = new int[b];
    }

    i=0;
    while(i<a){
        getLandValue(land[i],b);
        ++i;
    }

    if(a == 0 || b == 0){
        cout << 0 << endl;
        return 0;
    }

    int nProtected = n/m;
    // cout << nProtected << " axb: " << a*b << endl;
    if(nProtected == 0){
        cout << 0 << endl;
        return 0;
    }
    if(nProtected >= a*b){
        cout << sumLandValue(land,a,b) << endl;
        return 0;
    }
    findRatio(land,a,b,nProtected);
    return 0;
}
int lastFactor(int n){
    // use when >= 2
    int d = 2,last = 0;
    while(n>1){
        if(d>(n/d)){
            last = n;
            break;
        }
        if(n % d == 0){
            while(n%d==0){
                n/=d;
            }
            last = d;
        }
        if(d==2) ++d;
        else d+=2;

    }
    return last;
}
void findRatio(int **arr,short int a, short int b, int n){
    // cout << a << " " << b << " " << n << endl;
    short int row=1,col=1;
    long long int ratioSumMax=0,allRatioMax = LLONG_MIN;
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
    cout << allRatioMax << endl;

    // if (n == 1){
    //     ratioSumMax = findMostValueLand(arr,a,b,1,1);
    //     if(ratioSumMax > allRatioMax) allRatioMax = ratioSumMax;
    //     cout << ratioSumMax << endl;exit(0);
    // } 
    // short int lf,dlf,refLf,refDlf;
    // refLf = lastFactor(n);
    // refDlf = n/refLf;

    // // cout << refLf << " | " << refDlf << endl;

    // // dif = (lf > a ? lf - a : 0) + (dlf > b ? dlf - b : 0);
    // lf = (refLf > a ? refLf - (refLf-a) : refLf);
    // dlf = (refDlf > b ? refDlf - (refDlf-b) : refDlf);

    // while(lf < a && dif > 0){
    //     lf++;
    //     dif--;
    // }
    // while(dlf < b && dif > 0){
    //     dlf++;
    //     dif--;
    // }

    // // cout << lf << " | " << dlf << endl;
    // ratioSumMax = findMostValueLand(arr,a,b,lf,dlf);
    // if(ratioSumMax > allRatioMax) allRatioMax = ratioSumMax;

    // lf = (refLf > b ? refLf - (refLf-b) : refLf);
    // dlf = (refDlf > a ? refDlf - (refDlf-a) : refDlf);
    // // cout << dlf << " | " << lf << endl;

    // ratioSumMax = findMostValueLand(arr,a,b,dlf,lf);
    // if(ratioSumMax > allRatioMax) allRatioMax = ratioSumMax;

    // cout << ratioSumMax << endl;exit(0);



}
long long int sumLandValue(int **arr,short int a,short int b){
    short int r=0,c=0;
    long long int sumValue=0;
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

long long int findMostValueLand(int **arr,short int a,short int b,short int r, short int c){
    //row, col observe final and traversal;
    short int ro,co,rf,cf,rt,ct;
    long long int sumValue,maxRatioSumV=LLONG_MIN;
    
    ro = 0;
    rt = a - r + 1;
    while(ro<rt){
        
        rf = (ro + r) - 1;

        // cout << "rO-rF: " << ro << " - " << rf << endl;
    
        co=0;
        ct = b - c + 1;
        while(co<ct){
            sumValue=0;
            cf = (co + c) - 1;
            // cout << "cO-cF: " << co << " - " << cf << endl;
            for(short int i = ro;i<rf+1;i++){
                
                for(short int j = co;j<cf+1;j++){
                    // cout << j << " ";
                    // cout << arr[i][j] << "|";

                    sumValue += arr[i][j];

                }
                // cout << endl;
            }
            // cout << endl;
            if(sumValue > maxRatioSumV){
                maxRatioSumV = sumValue;
            }
            ++co;
            
        }
        // cout << endl;
        ++ro;
    }
    // cout << endl;
    // cout << "[" << r << "x" << c << "] sum: " << maxRatioSumV << endl;
    return maxRatioSumV;

}