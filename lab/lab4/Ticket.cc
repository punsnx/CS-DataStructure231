#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <stack>
#include <queue>
using namespace std;

void printTickets(stack<string> bottle,queue<string> line){
    cout << "Remaining Tickets In The Line: ";
    if(!line.empty()){
        while(!line.empty()){
            cout << line.front();
            line.pop();
            if(!line.empty())cout << " ";
        }
    }else cout << "Line Is Empty";
    cout << endl;

    cout << "Remaining Tickets In The Bottle: ";
    if(!bottle.empty()){
        stack<string> tmp;
        while(!bottle.empty()){
            tmp.push(bottle.top());
            bottle.pop();
        }
        while(!tmp.empty()){
            cout << tmp.top();
            tmp.pop();
            if(!tmp.empty())cout << " ";
        }
    }else cout << "Bottle Is Empty";
    cout << endl;
    cout << "====================" << endl;
}

bool isInBottle(stack<string> tmp,string str){
    while(!tmp.empty()){
        if(str == tmp.top())return true;
        tmp.pop();
    }
    return false;
}

int main(){
    stack<string> bottle;
    queue<string> line;
    string input;
    getline(cin,input);
    istringstream inputStream(input);
    string inLine;
    while (std::getline(inputStream, inLine, ' ')){ 
        size_t returnCharPos = inLine.find(13);
        if(returnCharPos != string::npos){
            inLine.erase(returnCharPos);
        }
        if (!inLine.empty() && !isInBottle(bottle,inLine)) {// no return char
            bottle.push(inLine);
        }
    }
    char c;
    // queue<char> command;
    // while(true){
    //     cin >> c;
    //     c = tolower(c);
    //     if(c == 'e' || c == 'd' || c == 'p'){
    //         command.push(c);
    //     }
    //     else {
    //         command.push(c);
    //         break;
    //     }
    // }
    while(true){
        // c = command.front();
        // command.pop();
        cin >> c;
        c = tolower(c);
        if(c == 'q')return 0;
        else if(c == 'e'){
            if(!bottle.empty()){
                line.push(bottle.top());
                bottle.pop();
            }
        }
        else if(c == 'd'){
            if(!line.empty()){
                bottle.push(line.front());
                line.pop();
            }
        }
        else if(c == 'p'){
            printTickets(bottle,line);
        }
        else {
            cout << "Input Error" << endl;
            return 0;
        }
    }
    return 0;

} 