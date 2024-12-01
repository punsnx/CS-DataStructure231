#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

double calOperator(double a, double b, char c) {
    switch (c) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}
bool isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/')return true;
    return false;
    
}
bool isOpenParenthesis(char c){
    if(c == '(')return true;
    return false;
}
bool isCloseParenthesis(char c){
    if(c == ')')return true;
    return false;
}

int main(){
    string str;
    cin >> str;
    stack<char> operatorStack;
    stack<string> postfixStack;
    int p = 0;
    string tmp = "";
    for(short i = 0;i<str.size();i++){
        char curChar = str[i];
        if(isOpenParenthesis(curChar)){
            operatorStack.push(curChar);
            p++;
        }
        else if(isCloseParenthesis(curChar)){
            if(!tmp.empty())postfixStack.push(tmp);
            tmp = "";
            while(!operatorStack.empty() && !isOpenParenthesis(operatorStack.top())){
                string o(1,operatorStack.top());
                postfixStack.push(o);
                operatorStack.pop();
            }
            if(isOpenParenthesis(operatorStack.top())){
                operatorStack.pop();
                p--;
            }else{
                cout << "Error: Unbalanced parenthesis" << endl;
                return 0;
            }
        }
        else if(isOperator(curChar)){
            operatorStack.push(curChar);
            if(!tmp.empty())postfixStack.push(tmp);
            tmp = "";
        }
        else if(isnumber(curChar) || curChar == '.'){
            tmp += curChar;
        }else{
            return 0;//end program
        }

    }
    if(p > 0){
            cout << "Error: Unbalanced parenthesis" << endl;
            return 0;
    }

    while(!operatorStack.empty()){
        string o(1,operatorStack.top());
        postfixStack.push(o);
        operatorStack.pop();
    }



 
    cout << endl << "p : " << p << endl;




    return 0;
}