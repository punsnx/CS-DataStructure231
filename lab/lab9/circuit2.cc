//PASS
#include <iostream>
#include <vector>
using namespace std;

typedef struct _Node{
    string type;
    bool bit;
    int leftChild;
    int rightChild;
}Node;


void postorder(Node &s,vector<Node> &nodeList){
    if (s.leftChild > -1){
        postorder(nodeList.at(s.leftChild),nodeList);
    }
    if (s.rightChild > -1){
        postorder(nodeList.at(s.rightChild),nodeList);
    }

    if(s.type == "NOT"){
        bool &leftBit = nodeList.at(s.leftChild).bit;
        s.type = "BIT";
        s.bit = !leftBit;
    }else{
        if(s.type == "AND"){
            bool &leftBit = nodeList.at(s.leftChild).bit;
            bool &rightBit = nodeList.at(s.rightChild).bit;
            s.type = "BIT";
            s.bit = leftBit && rightBit;
        }
        if(s.type == "OR"){
            bool &leftBit = nodeList.at(s.leftChild).bit;
            bool &rightBit = nodeList.at(s.rightChild).bit;
            s.type = "BIT";
            s.bit = leftBit || rightBit;
        }
    }

}


int main(){
    int n;
    cin >> n;

    vector<Node> nodeList(n);
    for(Node &node : nodeList){
        cin >> node.bit;
        node.type = "BIT";
        node.leftChild = -1;
        node.rightChild = -1;
    }
    string type;
    while(cin >> type){
        Node newNode = {type,0,-1,-1};
        if(type == "NOT"){
            cin >> newNode.leftChild;
        }else{
            cin >> newNode.leftChild;
            cin >> newNode.rightChild;
        }
        nodeList.push_back(newNode);
    }

    postorder(nodeList.back(),nodeList);
    cout << nodeList.back().bit << endl;  
    return 0;
}