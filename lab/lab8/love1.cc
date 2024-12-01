//PASS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct _Node {
    short key;
    bool isBurned;
    _Node* parent;
    _Node* leftChild;
    _Node* rightSibling;
} Node;

class Tree {
    int nNode;
    Node* rootNode;

    Node* createNewNode() {
        Node* newNode = new Node;
        newNode->key = 0;
        newNode->isBurned = false;
        newNode->parent = NULL;
        newNode->leftChild = NULL;
        newNode->rightSibling = NULL;
        return newNode;
    }

    void createRoot(short key) {
        Node* newNode = createNewNode();
        newNode->key = key;
        rootNode = newNode;
    }

public:
    Tree(short key) {
        createRoot(key);
    }

    void addNode(short key, Node* parent) {
        if (!parent) return;
        Node* newNode = createNewNode();
        newNode->key = key;
        Node* child = parent->leftChild;
        if (child) {
            while (child && child->rightSibling) {
                child = child->rightSibling;
            }
            child->rightSibling = newNode;
        }
        else {
            parent->leftChild = newNode;
        }
        newNode->parent = parent;
    }

    Node* searchPreorder(Node* start, short key) {
        if (start->key == key) {
            return start;
        }
        Node* child = start->leftChild;
        Node* result = NULL;
        while (child && result == NULL) {
            result = searchPreorder(child, key);
            child = child->rightSibling;
        }
        return result;
    }

    Node* getNode(short key) {
        return searchPreorder(rootNode, key);
    }

    void burnTree(Node* start) {
        queue<Node*> q;
        q.push(start);
        start->isBurned = true;
        cout << start->key << endl;

        while (!q.empty()) {
            int size = q.size();
            vector<int> toPrint;

            for (int i = 0; i < size; ++i) {
                Node* cur = q.front();
                q.pop();

                Node* parent = cur->parent;
                if (parent && !parent->isBurned) {
                    q.push(parent);
                    parent->isBurned = true;
                    toPrint.push_back(parent->key);
                }

                Node* child = cur->leftChild;
                while (child) {
                    if (!child->isBurned) {
                        q.push(child);
                        child->isBurned = true;
                        toPrint.push_back(child->key);
                    }
                    child = child->rightSibling;
                }
            }

            for (int key : toPrint) {
                cout << key << " ";
            }
            if (!toPrint.empty()) cout << endl;
        }
    }
};

int main() {
    short N, R, S;
    cin >> N >> R;
    Tree t(R);
    
    for (int i = 0; i < N - 1; i++) {
        short P, C;
        cin >> P >> C;
        t.addNode(C, t.getNode(P));
    }
    
    cin >> S;
    Node* start = t.getNode(S);
    t.burnTree(start);

    return 0;
}