#include <iostream>
using namespace std;

typedef struct _node
{
    int data;
    _node *left;
    _node *right;
}Node;

Node *newNode(int data){
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left =NULL;
    newNode->right = NULL;
    return newNode;
}
void addNode(Node **head, int data){
    Node *cur = *head,*prev=NULL;
    Node *new_node = newNode(data);
    if(*head == NULL){
        *head = new_node;
        return;
    }
    while(cur){
        prev = cur;
        cur = cur->right;
    }
    new_node->left = prev;
    prev->right = new_node;
}
int main(){
    Node *head = NULL;
    Node *first = newNode(3);
    Node *second = newNode(5);
    first->right = second;
    second->left = first;
}
// 6610402230 ศิริสุข ทานธรรม