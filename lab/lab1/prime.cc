#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;short exponent;
    cin >> n;
    if(n < 2 || n > INT_MAX) return 0;
    cout << n << " = ";
    int d = 2;
    while(n>1){
        if(d>(n/d)){
            cout << n;
            break;
        }
        if(n % d == 0){
            exponent = 0;
            while(n%d==0){
                ++exponent;
                n/=d;
            }
            if(exponent>1){
                cout << d << "^" << exponent;
            }
            else{
                cout << d;
            }
            if (n>1) cout << " x ";
        }
        if(d==2) ++d;
        else d+=2;

    }
    cout << endl;
    return 0;

}
