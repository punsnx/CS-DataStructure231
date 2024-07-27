#include <iostream>
using namespace std;

typedef struct _node
{
    unsigned int id;
    _node *next;
}Node;

void addNode(Node **head,unsigned int data){
    Node *cur=*head,*prev=NULL,*newNode = new Node;
    newNode->id = data;
    newNode->next = NULL;
    if(*head==NULL){
        *head = newNode;
        return;
    }
    while (cur){
        if(cur->id == data)return;
        prev=cur;
        cur=cur->next;
    }
    prev->next = newNode;
}
void printList(Node *head){
    Node *cur=head;
    if(head==NULL)return;
    while (cur){
        cout << cur->id;
        if(cur->next != NULL)cout << " ";
        cur=cur->next;
    }
    cout << endl;
    
}
int main(){
    Node *head = NULL;

    while(true){
        unsigned int n;
        cin >> n;
        if(n==0)break;
        addNode(&head,n);
    }
    printList(head);
    return 0;
}