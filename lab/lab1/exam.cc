#include <iostream>
using namespace std;

void getAns(int *arr,int n){
    short int i=0;
    while(i<n){
        cin >> arr[i];
        // cout << arr[i] << "|";
        ++i;
    }
    // cout << endl;

}
void sumScore(int *validArr,int *arr,int n,long int *score){
    *score = 0;
    short int i = 0;
    while(i<n){
        if(arr[i]==validArr[i]) ++(*score);
        ++i;
    }
}
int main(){
    short int s,n,i=0;
    cin >> s >> n;
    if((s<1 || s>10000)||(n<1 || n>1000))return 0;
    // cout << s << " " << n;
    int ansArray[s+1][n];
    while(i<s+1){
        getAns(ansArray[i],n);
        ++i;
    }

    i=1;
    long int sScore;
    while(i<s+1){
        sumScore(ansArray[0],ansArray[i],n,&sScore);
        if(i == s)cout << sScore;
        else cout << sScore << " ";
        ++i;
    }
    cout << endl;


}