#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef struct _groupTerms
{
    string type;
    double n;
} groupTerms;

void toZeroEquation(string equation,vector<string> *eList){
    bool equalSign=false;
    bool first = true;
    string tmp = "";
    for(int i = 0;equation[i]!=0;i++){
        if(equation[i] == '='){
            equalSign=true;
            // cout << tmp << " | ";
            eList->push_back(tmp);
            first = true;tmp="";
            continue;}
        if(!equalSign){
            if(!first && (equation[i] == '+'|| equation[i] == '-') ){
                // cout << tmp << " | ";
                eList->push_back(tmp);
                tmp="";
            }
            tmp += equation[i];
            first = false;
        }else{
            if(first && (equation[i] >= '0' && equation[i] <= '9')){
                tmp += '-';
            }
            else if(first && (equation[i] == '-')){
                tmp += '+';
                continue;
            }
            else if(!first && (equation[i] == '+'|| equation[i] == '-') ){
                // cout << tmp << " | ";
                eList->push_back(tmp);
                tmp="";
                if(equation[i] == '+'){
                    tmp += '-';
                }else if(equation[i] == '-'){
                    tmp += '+';
                }
                continue;
            }
            tmp += equation[i];
            first = false;
            if(!first && equation[i+1] == 0){
                // cout << tmp << " | ";
                eList->push_back(tmp);
                tmp="";
            }
        }
        
    }
}

void findCoefficient(string s,int start,double *tmp,bool isLiteral){
    int pos = 1;
    int dotPos = s.find(".");
    bool negative = false;
    for(int j = start-1;j>=0;j--){
        double E;
        if(dotPos != string::npos && j > dotPos){
            E = 1/pow(10,j-dotPos);
        }else if(dotPos != string::npos && j < dotPos){
            E = pos;
        }else{
            E = pos;
        }

        if(s[j] >= '0' && s[j] <= '9'){
            *tmp += (s[j] % 48) * E;
        }
        if(s[j] == '-'){*tmp *= -1;negative=true;}

        if(dotPos != string::npos){
            if(j<dotPos)pos *= 10;
        }else pos *= 10;
    }
    if(!isLiteral){
        *tmp = (*tmp == 0 ? (negative ? -1 : 1) * 1 : *tmp);
    }
} 

void gTerms(vector<string> *terms,vector<groupTerms> *gta){
    double nX1=0,nX2=0,nY1=0,nY2=0,C=0;
    for(short i = 0;i<terms->size();i++){
        string stmp = terms->at(i);
        double tmp;
        if(stmp.find("x") != string::npos){//x
            tmp = 0;
            if(stmp.find("x^2") != string::npos){
                findCoefficient(stmp,stmp.find("x^2"),&tmp,false);
                nX2 += tmp;
            }else{
                findCoefficient(stmp,stmp.find("x"),&tmp,false);    
                nX1 += tmp;
            }

        }else if(stmp.find("y") != string::npos){//y
            tmp = 0;
            if(stmp.find("y^2") != string::npos){
                findCoefficient(stmp,stmp.find("y^2"),&tmp,false);
                nY2 += tmp;
            }else{
                findCoefficient(stmp,stmp.find("y"),&tmp,false);
                nY1 += tmp;
            }
        }else {//Literal
            tmp = 0;
            findCoefficient(stmp,stmp.size(),&tmp,true);
            C += tmp;

        }
    }
    groupTerms gt;
    gt.type = "x^2";
    gt.n = nX2;
    gta->push_back(gt);
    gt.type = "y^2";
    gt.n = nY2;
    gta->push_back(gt);
    gt.type = "x";
    gt.n = nX1;
    gta->push_back(gt); 
    gt.type = "y";
    gt.n = nY1;
    gta->push_back(gt); 
    gt.type = "l";
    gt.n = C;
    gta->push_back(gt);

}

bool evalPos(short x,short y,char v,vector<groupTerms> *gta){
    double value = 0;
        for(short i = 0;i<gta->size();i++){
            string type = gta->at(i).type;
            double n = gta->at(i).n;
            if(type.find("x") != string::npos){
                if(type.find("x^2") != string::npos){
                    value += n * pow(x,2);
                }else{
                    value += n * x;
                }

            }else if(type.find("y") != string::npos){
                if(type.find("y^2") != string::npos){
                    value += n * pow(y,2);
                }else{
                    value += n * y;
                }
            }
        }
    if(value == 0)return 1;
    return 0;
}

int main() {
    short n;
    cin >> n;
    int pos[n][2];
    for(short i = 0;i<n;i++){
        cin >> pos[i][0] >> pos[i][1];
    }
    string equation;
    vector<string> terms;

    vector<groupTerms> gta;//group terms array
    cin >> equation;
    // cout << equation << endl;
    toZeroEquation(equation,&terms);
    // for(string &s : terms){
    //     cout << s << "|";
    // }
    // cout << endl;
    gTerms(&terms,&gta);
    // for(groupTerms &gt : gta){
    //     cout << gt.n << gt.type << "|";
    // }
    // cout << endl;

    //find min x or y each n
    for(short i = 0;i<n;i++){
        short minIdx;int min=INT_MAX;
        for(short j = 0;j<2;j++){
            if(pos[i][j] < min){min = pos[i][j];minIdx=j;}
        }
        char v;
        int x = pos[i][0];
        int y = pos[i][1];
        if(minIdx == 0) v = 'x';
        else v = 'y';

        bool correct = evalPos(x,y,v,&gta);
        // cout << "(" << x << ", " << y << ")" << " min : " << min << " " << (correct ? "TRUE" : "FALSE") << endl;
        cout << "(" << x << ", " << y << ")" << " " << (correct ? "TRUE" : "FALSE") << endl;
    }

}