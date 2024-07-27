#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>
using namespace std;
struct Term
{
    long l,x1,x2,y1,y2;
};

void findCoefficient(string &s,int start,long &tmp,bool isLiteral){
    int pos = 1;
    bool negative = false;
    for(int j = start-1;j>=0;j--){
        if(isdigit(s[j])){
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

void cal(string &,Term &,bool);

int main() {
    short n;
    cin >> n;
    
    int pos[n][2];
    for(short i = 0;i<n;i++){
        cin >> pos[i][0] >> pos[i][1];
    }

    string l="+",r="+";
    {
        string e;//equation
        cin >> e;
        // cout << e << endl;
        size_t equalPos = e.find("=");
        e[equalPos] = 0;
        l += &e[0];
        r += &e[equalPos+1];
    }
    
    Term term = {0};
    string key = "+-";
    // cout << l << endl;
    char *p = strpbrk(&l[0],&key[0]);
    char *prev;
    while(p!=NULL){
        string tmp;
        prev = p;
        p = strpbrk(p+1,&key[0]);
        tmp = l.substr(prev-&l[0],p-prev);
        cal(tmp,term,false);
        // cout << tmp << endl;
    }
    // cout << endl;

    // cout << r << endl;
    p = strpbrk(&r[0],&key[0]);
    while(p!=NULL){
        string tmp;
        prev = p;
        p = strpbrk(p+1,&key[0]);
        tmp = r.substr(prev-&r[0],p-prev);
        cal(tmp,term,true);
        // cout << tmp << endl;
    }
    // cout << term.l << " " << term.x1 << " " << term.x2 << " " << term.y1 << " " << term.y2 <<endl;
    for(short i=0;i<n;i++){
        int x=pos[i][0],y=pos[i][1];
        long lvalue = term.l + (x*term.x1) + (x*x*term.x2) + (y*term.y1) + (y*y*term.y2);
        bool correct = (lvalue == 0);
        cout << "(" << x << ", " << y << ")" << " " << (correct ? "TRUE" : "FALSE") << endl;
    }
}
void cal(string &s,Term &t,bool isR){
    size_t pos;
    long tmp = 0;
    short i = (isR ? -1 : 1);
    if((pos = s.find("x^2")) != string::npos){
        findCoefficient(s,pos,tmp,false);
        tmp *= i;t.x2 += tmp;
    }else if ((pos = s.find("x")) != string::npos){
        findCoefficient(s,pos,tmp,false);
        tmp *= i;t.x1 += tmp;
    }else if ((pos = s.find("y^2")) != string::npos){
        findCoefficient(s,pos,tmp,false);
        tmp *= i;t.y2 += tmp;
    }else if ((pos = s.find("y")) != string::npos){
        findCoefficient(s,pos,tmp,false);
        tmp *= i;t.y1 += tmp;
    }else {
        findCoefficient(s,s.size(),tmp,true);
        tmp *= i;t.l += tmp;
    }
    // cout << tmp << endl;
}