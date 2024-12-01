#include <iostream>
using namespace std;

void maxHeapify(int arr[], int i, int n){
    int l,r,swap;
    l = 2 * i;
    r = 2 * i + 1;
    swap = i;
    if (l <= n && arr[l] > arr[swap]){
        swap = l;
    }
    if (r <= n && arr[r] > arr[swap]){
        swap = r;
    }
    if(swap != i){
        int tmp = arr[i];
        arr[i] = arr[swap];
        arr[swap] = tmp;
        maxHeapify(arr,swap,n);
    }
}
void buildMaxHeap(int arr[],int n){
    for(int i = n/2;i>=1;--i){
        maxHeapify(arr,i,n);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n+1];//store 1 - n
    for(int i = 1;i<=n;++i){
        cin >> arr[i];
    }
    buildMaxHeap(arr,n);
    for(int i = 1;i<=n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}