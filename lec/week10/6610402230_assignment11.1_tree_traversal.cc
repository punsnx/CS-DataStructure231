// 6610402230 Sirisuk Tharntham

#include <iostream>
#include <vector>
using namespace std;

typedef struct _Node{
    string key;
    int size;
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
        newNode->key = "";
        newNode->size = 0;
        newNode->parent = NULL;
        newNode->leftChild = NULL;
        newNode->rightSibling = NULL;
        return newNode;
    }
    void createRoot(string key,int size){
        Node *newNode = createNewNode();
        newNode->key = key;
        newNode->size = size;
        rootNode = newNode;
        // treeNode.push_back(newNode);
    }
public:
    Tree(string key,int size){
        createRoot(key,size);
    }
    void addNode(string key,int size,Node *parent){
        if(!parent)return;
        Node *newNode = createNewNode();
        newNode->key = key;
        newNode->size = size;
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
    void postPorder(Node *start,int &size){
        Node *child = start->leftChild;
        int tmp;
        if(child){
            tmp = size;
            size = 0;
        }
        while(child){
            postPorder(child, size);
            child = child->rightSibling;
        }
        size += start->size;
        if(start->leftChild){
            cout << start->key << " : " << size << "K" << endl;
            size += tmp;
        }

    }
    void printTreePostorder(){
        int size = 0;
        postPorder(rootNode,size);
    }
    Node *searchPreorder(Node *start,string key){
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
    Node *getNode(string key){
        return searchPreorder(rootNode,key);
    }

};


int main(){
    Tree t("/user/rt/courses/",1);
    t.addNode("cs016",2,t.getNode("/user/rt/courses/"));

    t.addNode("grades",8,t.getNode("cs016"));
    t.addNode("homeworks",1,t.getNode("cs016"));
    t.addNode("programs",1,t.getNode("cs016"));

    t.addNode("hw1",3,t.getNode("homeworks"));
    t.addNode("hw2",2,t.getNode("homeworks"));
    t.addNode("hw3",4,t.getNode("homeworks"));

    t.addNode("pr1",57,t.getNode("programs"));
    t.addNode("pr2",97,t.getNode("programs"));
    t.addNode("pr3",74,t.getNode("programs"));

    t.addNode("cs252",1,t.getNode("/user/rt/courses/"));

    t.addNode("projects",1,t.getNode("cs252"));
    t.addNode("grades",3,t.getNode("cs252"));

    t.addNode("papers",1,t.getNode("projects"));
    t.addNode("demos",1,t.getNode("projects"));

    t.addNode("buylow",26,t.getNode("papers"));
    t.addNode("sellhigh",55,t.getNode("papers"));

    t.addNode("market",4786,t.getNode("demos"));



    t.printTreePostorder();









    return 0;
}
