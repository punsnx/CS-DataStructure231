#include <iostream>
#include <stack>
#include <queue>
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
    queue<string> postfixQueue;
    stack<string> post;
    int p = 0;
    string tmp = "";
    for(short i = 0;i<str.size();i++){
        // cout << tmp << endl;
        char curChar = str[i];
        if(isOpenParenthesis(curChar)){
            operatorStack.push(curChar);
            p++;
        }
        else if(isCloseParenthesis(curChar)){
            if(!tmp.empty())postfixQueue.push(tmp);
            tmp = "";
            while(!operatorStack.empty() && !isOpenParenthesis(operatorStack.top())){
                string o(1,operatorStack.top());
                postfixQueue.push(o);
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
            if(i == str.size()-1) continue;;
            if(i < str.size()-1 && isCloseParenthesis(str[i+1]))continue;
            if(i < str.size() && i == 0 && !isdigit(str[i+1]))continue;
            if(i < str.size() && i > 0 && isOpenParenthesis(str[i-1]) && isOpenParenthesis(str[i+1]))continue;
            if(i == 0 || (!operatorStack.empty() && isOpenParenthesis(operatorStack.top()) && tmp.empty())){
                // cout << "RUN" << i << endl;
                if(curChar == '+' || curChar == '-'){
                    string o(1,curChar);
                    tmp = o + tmp;
                    continue;

                }
            }
            operatorStack.push(curChar);
            if(!tmp.empty())postfixQueue.push(tmp);
            tmp = "";
        }
        else if(isdigit(curChar) || curChar == '.'){
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
        postfixQueue.push(o);
        operatorStack.pop();
    }

    while(!postfixQueue.empty()){
        string cur = postfixQueue.front();
        // cout << cur << " ";
        if(isOperator(cur[0]) && cur.size() == 1){
            char o = cur[0];
            if(post.size() >= 2){
                string rightOperand = post.top();
                post.pop();
                string leftOperand = post.top();
                post.pop();
                
                double cal = calOperator(atof(&leftOperand[0]),atof(&rightOperand[0]),o);
                // cout << cal << cur << " ";
                post.push(to_string(cal));
            }
        }else{
            post.push(cur);
        }
        postfixQueue.pop();
    }
 
    // cout << endl;
    // cout << endl << "p : " << p << endl;
    if(post.size() == 1){
        double ans = atof(&post.top()[0]);
        post.pop();
        printf("%.2f",ans);
    }else{
        return 0;
    }




    return 0;
}