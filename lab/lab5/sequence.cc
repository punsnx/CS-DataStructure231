#include <iostream>
using namespace std;

typedef struct _Node {
    int data;
    _Node *next;
} Node;

Node *createNode(){
    Node *newNode = new Node;
    newNode->next = NULL;
    return newNode;
}
void addNode(Node **head,int data){
    Node * newNode = createNode();
    newNode->data = data;

    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node *cur = *head;
    while(cur && cur->next != NULL){
        cur=cur->next;
    }

    cur->next = newNode;
}

int getTetrahedal(Node *head,int n){
    if(n == 0){
        return 0;
    }else{
        int data = head->data;
        Node *next = head->next;
        return data +  getTetrahedal(next,--n);
    }
}
int main(){
    Node *nList = NULL;
    string in;
    short nMax = 0;
    //STOP WHEN GETLINE FOUND EOF
    while(getline(cin,in)){
        int n = stoi(in);
        addNode(&nList,n);
        if(n > nMax)nMax = n;
    }
    Node *Tn = NULL;
    int sum = 0;
    for(short i = 1;i<=nMax;i++){
        sum += i;
        addNode(&Tn,sum);
    }
    Node *cur = nList;
    while(cur){
        int n = cur->data;
        int data = getTetrahedal(Tn,n);
        cout << data << endl;
        cur = cur->next;
    }


}