#include <iostream>
#include <queue>
#include <vector> 
using namespace std;

typedef struct _Node{
    string c;
    _Node *leftChild;
    _Node *rightChild;
    _Node *parent;
}Node;

class Tree{
public:
    Node* root;
    int n;
    vector<string> order;
    Tree(string e){
        n = 0;
        root = bTreeExpression(e);
        reverseTree(root);
        order = vector<string>(n,"");
        //pre post in level
        visit(root);
        visitLevelOrder(root);
    }
    Node* bTreeExpression(string e){
            
            size_t qSign = e.find("?");
            size_t cSign = e.rfind(":");
            string node = e.substr(0,qSign-0);
            string left = e.substr(qSign+1,cSign-qSign-1);
            string right = e.substr(cSign+1);
            Node *newNode = createNode(node);
            
            if(left.length() == 1){
                createLeft(left,newNode);
                n++;
            }else{
                Node *leftNode = bTreeExpression(left);
                newNode->leftChild = leftNode;
                leftNode->parent = newNode;
            }
            if(right.length() == 1){
                createRight(right,newNode);
                n++;
            }else{
                Node *rightNode = bTreeExpression(right);
                newNode->rightChild = rightNode;
                rightNode->parent = newNode;
            }
            n++;
            return newNode;
    }

    Node *createNode(string c){
        Node *newNode = new Node;
        newNode->c = c;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        return newNode;
    }
    void createLeft(string c,Node *parent){
        Node *newNode = createNode(c);
        parent->leftChild = newNode;
        newNode->parent = parent;
    }
    void createRight(string c,Node *parent){
        Node *newNode = createNode(c);
        parent->rightChild = newNode;
        newNode->parent = parent;
    }
    void reverseTree(Node *s){
        Node *tmpChild = s->leftChild;
        s->leftChild = s->rightChild;
        s->rightChild = tmpChild;

        if (s->leftChild){
            reverseTree(s->leftChild);
        }

        if (s->rightChild){
            reverseTree(s->rightChild);
        }
    }
    void visit(Node *s){
        order[0] += s->c; //preorder
        if (s->leftChild){
            visit(s->leftChild);
        }
        order[2] += s->c; //inorder
        if (s->rightChild){
            visit(s->rightChild);
        }
        order[1] += s->c; //postorder

    }
    void visitLevelOrder(Node* root) {
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            
            order[3] += current->c; //visit levelorder
            
            if (current->leftChild) {
                q.push(current->leftChild);
            }
            if (current->rightChild) {
                q.push(current->rightChild);
            }
        }
    }

};

int main(){
    string e,key;
    cin >> e;
    cin >> key;
    Tree t(e);

    vector<int> sum(4,0);

    for(int row = 0;row < 4;row++){
        string chars = t.order.at(row);
        for(int col = 0;col < t.n;col++){
            // cout << chars[col] << " ";
            if(chars[col] == key[0]){
                int count = 0;
                int back = 0,forward = 0,up = 0,down = 0;
                int cb = col,cf = col;
                int ru = row,rd = row;
                for(int i = 0;i < key.length();i++,cb--,cf++,ru--,rd++){
                    if(cb >= 0 && chars[cb] == key[i])back++;
                    if(cf < t.n && chars[cf] == key[i])forward++;
                    if(ru >= 0 && t.order.at(ru)[col] == key[i])up++;
                    if(rd < 4 && t.order.at(rd)[col] == key[i])down++;
                }
                int length = key.length();
                count += (back == length)+(forward==length)+(up==length)+(down==length);
                sum.at(row) += count * (col+row);
        

            }
        }
        // cout << endl;

    }
    for(int &s : sum){
        cout << s%10;
    }
    cout << endl;

    


    return 0;
}