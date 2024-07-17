#include <iostream>
#include <climits>
#include <cmath>
#include <string>
using namespace std;
bool eval(string,int,int);
void cal(string *,int,int,long *);
bool isA(char c){
    if((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z'))return 1;
    return 0;
}
bool isN(char c){
    if(c >= '0' && c <= '9')return 1;
    return 0;
}
void findCoefficient(string s,int start,double *tmp,bool isLiteral){
    int pos = 1;
    // int dotPos = s.find(".");//comment for no flating points
    bool negative = false;
    for(int j = start-1;j>=0;j--){
        double E;
        E = pos;
        // if(dotPos != string::npos && j > dotPos){
        //     E = 1/pow(10,j-dotPos);
        // }else if(dotPos != string::npos && j < dotPos){
        //     E = pos;
        // }else{
        //     E = pos;
        // }

        if(s[j] >= '0' && s[j] <= '9'){
            *tmp += (s[j] % 48) * E;
        }
        if(s[j] == '-'){*tmp *= -1;negative=true;}

        // if(dotPos != string::npos){
        //     if(j<dotPos)pos *= 10;
        // }else pos *= 10;
        pos *= 10;
    }
    if(!isLiteral){
        *tmp = (*tmp == 0 ? (negative ? -1 : 1) * 1 : *tmp);
    }
} 

int main(){
    short n;cin >> n;
    int pos[n][2];
    for(short i=0;i<n;i++){cin >> pos[i][0] >> pos[i][1];}
    string equation;
    cin >> equation;
    // cout << equation << endl;
    //find min x or y each n
    for(short i = 0;i<n;i++){
        int x = pos[i][0], y = pos[i][1];
        bool correct = eval(equation,x,y);
        cout << "(" << x << ", " << y << ")" << " " << (correct ? "TRUE" : "FALSE") << endl;
    }
    return 0;
}

bool eval(string e,int x,int y){
    // short equalPos = e.find("=");
    bool negativeFirst = false;
    // for(short i = equalPos;i<e.size();i++){
    //     if (i == equalPos && e[i+1] != 0 && e[i+1] == '-')negativeFirst=true;
    //     if(e[i] == '-')e[i]='+';
    //     else if(e[i] == '+')e[i]='-';
    // }
    // if(negativeFirst)e.erase(equalPos,1);
    // else e[equalPos] = '-';

    long lvalue=0;
    bool first = true;negativeFirst=false;
    bool afterEqual=false;
    string stmp="";
    for(short i = 0;i<e.size();i++){
        if(e[i] == '='){
            afterEqual=true;
            if(isN(e[i+1]))e[i]='+';
            else if(e[i+1] == '-' || e[i+1] == '+') continue;//check + not nesessary
        }
        if(!first && !afterEqual && (e[i]=='+'||e[i]=='-')){
            // cout << stmp << "|";
            cal(&stmp,x,y,&lvalue);
            stmp = "";
        }
        if(!first && afterEqual && (e[i]=='+'||e[i]=='-')){
            if(e[i]=='+')e[i]='-';
            else if(e[i]=='-')e[i]='+';

            cal(&stmp,x,y,&lvalue);
            stmp = "";
        }
        stmp += e[i];
        if(first)first=false;
        if(e[i+1]==0){
            // cout << stmp << "|";
            cal(&stmp,x,y,&lvalue);
            stmp = "";
        }
    }
    // cout << endl;
    // cout << lvalue << endl;
    if(lvalue == 0)return 1;
    return 0;
}
void cal(string *s,int x,int y,long *l){
    double tmp;
    if(s->find("x") != string::npos){
        tmp = 0;
        if(s->find("x^2")!= string::npos) {
            findCoefficient(*s,s->find("x^2"),&tmp,false);
            // cout << tmp << "x^2|";
            tmp *= (((long)x)*x);
        }
        else {
            findCoefficient(*s,s->find("x"),&tmp,false);
            // cout << tmp << "x|";
            tmp *= x;
        }
        
    }else if(s->find("y")!= string::npos){
        tmp = 0;
        if(s->find("y^2")!= string::npos){
            findCoefficient(*s,s->find("y^2"),&tmp,false);
            // cout << tmp << "y^2|";
            tmp *= (((long)y)*y);
        }
        else {
            findCoefficient(*s,s->find("y"),&tmp,false);
            // cout << tmp << "y|";
            tmp *= y; 
        }
        
    }else{
        tmp = 0;
        findCoefficient(*s,s->size(),&tmp,true);
        // cout << tmp << "|";
    }
    *l += tmp;

}