#include <iostream>
using namespace std;

bool isAlpha(char c){
    if((c>=65 && c<=90)||(c>=97 && c<=122))return true;
    return false;
}
bool isUpper(char c){
    if(c>=65 && c<=90)return true;
    return false;
}
bool isNumber(char c){
    if(c>=48 && c<=57)return true;
    return false;
}
int main() {
    string s;
    cin >> s;
    int i = 0;
    char c = s[i];
    bool first = true;
    while(c != 0){
        if(first){
            if (isNumber(c)){
                cout << c;
                c = s[++i];
                continue;
            }
            else if(!isUpper(c)){
                c = (char)(c-32);
            }
            if(i>0 && isNumber(s[i-1]))cout << " ";
            cout << c;
            first = false;
            
        }
        else if(isNumber(c) && isAlpha(s[i-1])){
            cout << " " << c;
            first = true;
        }
        else if(isUpper(c) && (!isUpper(s[i-1]) || isNumber(s[i-1]))){
            cout << " " << c;
        }
        else if(isUpper(c) && s[i+1] != 0 && (isUpper(s[i-1]) && (isAlpha(s[i+1]) && !isUpper(s[i+1])))){
            cout << " " << c;
        }
        else if(!isUpper(c) && isNumber(s[i-1])){
            cout << " " << c;
        }else {
            cout << c;
        }

        c = s[++i];
        
    }


}