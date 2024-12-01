// 6610402230 Sirisuk Tharntham

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct _Node{
    short key;
    bool isBurned;
    _Node *parent;
    _Node *leftChild;
    _Node *rightSibling;
}Node;

class Tree{
    int nNode;
    Node *rootNode;
    // vector<Node*> treeNode;
    Node *createNewNode(){
        Node *newNode = new Node;
        newNode->key = 0;
        newNode->isBurned = false;
        newNode->parent = NULL;
        newNode->leftChild = NULL;
        newNode->rightSibling = NULL;
        return newNode;
    }
    void createRoot(short key){
        Node *newNode = createNewNode();
        newNode->key = key;
        rootNode = newNode;
        // treeNode.push_back(newNode);
    }
public:
    Tree(short key){
        createRoot(key);
    }
    void addNode(short key,Node *parent){
        if(!parent)return;
        Node *newNode = createNewNode();
        newNode->key = key;
        Node *child = parent->leftChild;
        if(child){
            while(child && child->rightSibling){
                child = child->rightSibling;
            }
            child->rightSibling = newNode;
        }else{
            parent->leftChild = newNode;
        }
        newNode->parent = parent;
        // treeNode.push_back(newNode);
    }
    void postPorder(Node *start){
        Node *child = start->leftChild;
        while(child){
            postPorder(child);
            child = child->rightSibling;
        }
        cout << start->key << endl;

    }
    void printTreePostorder(){
        int size = 0;
        postPorder(rootNode);
    }
    Node *searchPreorder(Node *start,short key){
        Node *returnValue = NULL;
        //visit start
        if(start->key == key){
            return start;
        }

        Node *child = start->leftChild;
        while(child && returnValue == NULL){
            returnValue = searchPreorder(child,key);
            child = child->rightSibling;
        }
        return returnValue;

    }
    Node *getNode(short key){
        return searchPreorder(rootNode,key);
    }

};

int main(){
    short N,R,S;
    cin >> N;
    cin >> R;
    Tree t(R);
    for(int i = 0;i<N-1;i++){
        short P,C;
        cin >> P >> C;
        t.addNode(C,t.getNode(P));
    }
    cin >> S;
    // t.printTreePostorder();

    Node *start = t.getNode(S);
    //start burn
    queue<Node*> q;
    q.push(start);
    start->isBurned = true;
    cout << start->key << endl;

    while(!q.empty()){
        Node *cur = q.front();
        q.pop();

        Node *parent = cur->parent;
        if(parent && parent->isBurned == false){
            q.push(parent);
            parent->isBurned = true;
            cout << parent->key << " ";
        }
        Node *child = cur->leftChild;
        while(child){
            q.push(child);
            if(child->isBurned == false){
                cout << child->key << " ";
            }
            child->isBurned = true;
            child = child->rightSibling;
        }
        cout << endl;



    }


    return 0;
}