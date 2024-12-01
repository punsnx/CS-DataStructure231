#include <iostream>
using namespace std;

int a(int n,int sum){
    if(n==1){
        return 2;
    }else {
        return a(n-1,n+sum)+3;
    }
}
int main(){

    for(int n = 1;n<=3;n++){
    cout << a(n,0) << endl;
    }
    return 0;
}
// ศิริสุข ทานธรรม 6610402230