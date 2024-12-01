//NOT PASS
#include <iostream>
#include <list>
using namespace std;

typedef struct _Node{
    string op;
    bool key;
    _Node *parent;
    _Node *leftChild;
    _Node *rightChild;
}Node;

class Tree{
    list<bool> operand;
public: 
    Node *root;
    list<Node*> nodeList;
    Tree(int n){
        for(int i = 0;i<n;i++){
            bool bit;
            cin >> bit;
            nodeList.push_back(createNode("BIT",bit));
        }
    }
    Node* createNode(string op,bool key){
        Node *newNode = new Node;
        newNode->op = op;
        newNode->key = key;
        newNode->parent = NULL;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        return newNode;
    }
    void linkLeft(Node *node,Node *parent){
        parent->leftChild = node;
        node->parent = parent;
    }
    void linkRight(Node *node,Node *parent){
        parent->rightChild = node;
        node->parent = parent;
    }
    Node *getNode(int idx){ 
        list<Node*>::iterator itr = nodeList.begin();
        for(int i = 0;i<idx;i++){
            ++itr;
        }
        return *itr;
    }
    void postorder(Node *s){
        if (s->leftChild){
            postorder(s->leftChild);
        }

        if (s->rightChild){
            postorder(s->rightChild);
        }
    
        if(s->op == "BIT"){
            operand.push_back(s->key);
        }else{
            bool l,r,answer;
            if(s->op == "NOT"){
                l = operand.back();
                operand.pop_back();
                
                answer = !l;
            }else{
                r = operand.back();
                operand.pop_back();
                l = operand.back();
                operand.pop_back();

                if(s->op == "AND"){
                    answer = l && r;
                }else if(s->op == "OR"){
                    answer = l || r;
                }
            }
            
            s->op = "BIT";
            s->key = answer;
            operand.push_back(s->key);
        }


    }

};
int main(){
    int n;
    cin >> n;
    Tree t(n);
    string op;
    while(cin >> op){
        Node *newNode = t.createNode(op,0);
        int l,r;
        Node *left,*right;
        if(op != "NOT"){
            cin >> l >> r;
            left = t.getNode(l);
            right = t.getNode(r);
            t.linkLeft(left,newNode);
            t.linkRight(right,newNode);
        }else{
            cin >> l;
            left = t.getNode(l);
            t.linkLeft(left,newNode);
        }
        t.nodeList.push_back(newNode);
    }
    t.root = t.nodeList.back();
    t.postorder(t.root);
    cout << t.root->key << endl;


}