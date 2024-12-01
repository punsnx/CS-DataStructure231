//PASS
#include <iostream>
#include <queue>
#include <list>
using namespace std;

typedef struct _Node{
    int key;
    _Node *parent;
    _Node *leftChild;
    _Node *rightChild;
}Node;

class BTree{
public:
    Node *root;
    int sum,i;
    BTree(int n){//n = 1 to 10000
        this->i = 0;
        this->sum = 0;
        int i = 1;
        createRoot(i++);
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node *cur = q.front();
            q.pop();
            Node *left,*right;
            if(i <= n) {
                left = createLeft(i++,cur);
                q.push(left);
            }
            if(i <= n) {
                right = createRight(i++,cur);  
                q.push(right);
            }

        }
        
    }
    Node* createNode(int key){
        Node *newNode = new Node;
        newNode->key = key;
        newNode->parent = NULL;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        return newNode;
    }
    void createRoot(int key){
        root = createNode(key);
    }
    Node* createLeft(int key,Node *parent){
        Node* newNode = createNode(key);
        parent->leftChild = newNode;
        newNode->parent = parent;
        return newNode;
    }
    Node* createRight(int key,Node *parent){
        Node* newNode = createNode(key);
        parent->rightChild = newNode;
        newNode->parent = parent;
        return newNode;
    }
    
    void postorder(Node *s){
        if(s->parent) {
            ++i;
            if(i%2 == 1){
                sum += s->parent->key;
            }else{
                sum -= s->parent->key;
            }
        };
        if (s->leftChild){
            postorder(s->leftChild);
        }
        if (s->rightChild){
            postorder(s->rightChild);
        }

        ++i;
        if(i%2 == 1){
            sum += s->key;
        }else{
            sum -= s->key;
        }
    }
    Node *getRoot(){
        return root;
    }



};

int main(){
    int n;
    cin >> n;
    BTree t(n);
    t.postorder(t.root);
    cout << t.sum << endl;







    
}