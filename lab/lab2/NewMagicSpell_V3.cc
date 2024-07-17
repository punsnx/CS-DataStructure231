#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

typedef struct _groupTerms
{
    string type;
    short n;
} groupTerms;

void eval(string &,vector<groupTerms> &);
bool cal(string &,int,int,short,long &,bool);
bool isA(char c){return (c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z');}
bool isN(char c){return (c >= '0' && c <= '9');}
void findCoefficient(string &s,int start,long &tmp,bool isLiteral){
    int pos = 1;
    bool negative = false;
    for(int j = start-1;j>=0;j--){
        if(s[j] >= '0' && s[j] <= '9'){
            tmp += (s[j] % 48) * pos;
        }else if(s[j] == '-'){
            tmp *= -1;negative=true;
        }else if(s[j] == '+') continue;
        else break;
        pos *= 10;
    }
    if(!isLiteral){
        tmp = (tmp == 0 ? (negative ? -1 : 1) * 1 : tmp);
    }
} 

int main(){


    short n;cin >> n;
    int pos[n][2];
    for(short i=0;i<n;i++){cin >> pos[i][0] >> pos[i][1];}
    string equation;
    cin >> equation;
    vector<groupTerms> splitEquation;
    eval(equation,splitEquation);

    // cout << equation << endl;
    for(short i = 0;i<n;i++){
        long lvalue=0;
        int x = pos[i][0], y = pos[i][1];
        short splitSize = splitEquation.size();
        if(splitSize>0){
            for(short j = 0;j<splitSize;j++){
                bool valid = cal(splitEquation[j].type,x,y,splitEquation[j].n,lvalue,true);
                if(!valid){
                    lvalue=LONG_MAX;
                    break;
                }
            }
        }else lvalue=LONG_MAX;;

        bool correct = (lvalue == 0);
        cout << "(" << x << ", " << y << ")" << " " << (correct ? "TRUE" : "FALSE") << endl;
    }

    return 0;
}

void eval(string &e,vector<groupTerms> &se){
    bool first = true;
    bool afterEqual=false;
    string stmp="";
    long tmp;
    groupTerms gt;
    for(short i = 0;i<e.size();i++){
        if(e[i] == '='){
            afterEqual=true;
            if(isN(e[i+1]))e[i]='+';
            else if(e[i+1] == '-' || e[i+1] == '+') continue;//check + not nesessary
        }
        if(!first && !afterEqual && (e[i]=='+'||e[i]=='-')){
            // cout << stmp << "|";
            tmp = 0;
            cal(stmp,0,0,0,tmp,false);
            gt.type=stmp;
            gt.n=tmp;
            se.push_back(gt);
            stmp = "";
        }
        if(!first && afterEqual && (e[i]=='+'||e[i]=='-')){
            if(e[i]=='+')e[i]='-';
            else if(e[i]=='-')e[i]='+';
            
            tmp = 0;
            cal(stmp,0,0,0,tmp,false);
            gt.type=stmp;
            gt.n=tmp;
            se.push_back(gt);
            stmp = "";
        }
        stmp += e[i];
        if(first)first=false;
        if(e[i+1]==0){
            // cout << stmp << "|";

            tmp = 0;
            cal(stmp,0,0,0,tmp,false);
            gt.type=stmp;
            gt.n=tmp;
            se.push_back(gt);
            stmp = "";
        }
    }
}

bool cal(string &s,int x,int y,short coefficient,long &l,bool needCal){
    long tmp;
    if(needCal) tmp = coefficient;
    if(s.find("x") != string::npos){
        if(!needCal) tmp = 0;
        if(s.find("x^2")!= string::npos) {
            if(!needCal) findCoefficient(s,s.find("x^2"),tmp,false);
            if(needCal) tmp *= (((long)x)*x);
            // cout << tmp << "x^2|";
        }else if(needCal && s.find("x^")!= string::npos){
            return false;
        }
        else {
            if(!needCal) findCoefficient(s,s.find("x"),tmp,false);
            if(needCal) tmp *= x;
            // cout << tmp << "x|";
        }
        
    }else if(s.find("y")!= string::npos){
        if(!needCal) tmp = 0;
        if(s.find("y^2")!= string::npos){
            if(!needCal) findCoefficient(s,s.find("y^2"),tmp,false);
            if(needCal) tmp *= (((long)y)*y);
            // cout << tmp << "y^2|";
        }else if(needCal && s.find("y^")!= string::npos){
            return false;
        }
        else {
            if(!needCal) findCoefficient(s,s.find("y"),tmp,false);
            if(needCal) tmp *= y; 
            // cout << tmp << "y|";
        }
        
    }else{
        if(!needCal) tmp = 0;
        if(!needCal) findCoefficient(s,s.size(),tmp,true);
        // cout << tmp << "|";
    }
    l += tmp;
    return true;
}