#include <iostream>
#include <stack>
using namespace std;

typedef struct _tower{
    string name;
    stack<int> towerStack;
} Tower;

void move(int n, Tower &towerSource,Tower &towerTemp,Tower &towerDest){
    stack<int> &source = towerSource.towerStack;
    stack<int> &dest = towerDest.towerStack;

    for(int i = 0;i<n;i++){
        if(!source.empty()){
            dest.push(source.top());
            source.pop();
        }
    }
    cout << "move(" << n << "," << towerSource.name << "," << towerTemp.name << "," << towerDest.name << ")" << endl;
}
void printTower(Tower towerTmp){
    stack<int> &tmp = towerTmp.towerStack;
    stack<int> reverseStack;
    cout << towerTmp.name << ": ";
    while(!tmp.empty()){
        reverseStack.push(tmp.top());
        tmp.pop();
    }
    while(!reverseStack.empty()){
        cout << reverseStack.top();
        reverseStack.pop();
        if(!reverseStack.empty())cout <<  " ";
    }
    cout << endl;
}
int main(){

    Tower A,B,C;
    A.name = "A";
    B.name = "B";
    C.name = "C";
    //init n = 3
    int n = 3;
    for(int data = n-1;data >= 0;data--){
        A.towerStack.push(data);
    }
    cout << "Start" << endl;
    printTower(A);
    printTower(B);
    printTower(C);
    //start move
    move(1,A,C,B);
    printTower(A);
    printTower(B);
    printTower(C);

    move(1,A,C,B);
    printTower(A);
    printTower(B);
    printTower(C);

    move(1,A,B,C);
    printTower(A);
    printTower(B);
    printTower(C);

    move(1,B,A,C);
    printTower(A);
    printTower(B);
    printTower(C);

    move(1,B,A,C);
    printTower(A);
    printTower(B);
    printTower(C);
}
//Sirisuk Tharntham 6610402230