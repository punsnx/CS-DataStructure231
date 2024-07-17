#include <iostream>
using namespace std;
void loop(long int n){
    // int h;
    // cout << sizeof(n);
    short exponent;
    // cin >> n;
    if(n < 2 || n > 2147483647) return;
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
}
int main() {
    long int i = 2;
    while(i<101){
        loop(i);
        ++i;
    }
    return 0;

}
