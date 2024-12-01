#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &x) {
    int left = 0;
    int right = x.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
    
        if (x[mid] == mid + 1) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return left + 1;
}


int main(){
    int n;
    vector<int> data;
    cin >> n;
    for(int i = 0;i<n;i++){
        int tmp;
        cin >> tmp;
        data.push_back(tmp);
    }

    cout << binarySearch(data) << endl;;

}