#include <iostream>
using namespace std;

typedef struct _node
{
    short id;
    short origin;
    _node *next;
    _node *prev;
}node;

void addNode(node **head,short data ){//CIRCULAR DOUBLY LINKLSIT
    node *newNode = new node;
    newNode->id = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(*head==NULL){
        *head = newNode;
        newNode->next = *head;
        newNode->prev = *head;
        return;
    }
    node *cur=*head;
    while(cur->next != *head){
        cur = cur->next;
    }
    newNode->next = *head;
    newNode->prev = cur;
    cur->next = newNode;

}
void printList(node *head){//PRINT LIST CIRCULAR DOUBLY LINKLSIT
    node *cur = head;
    while(cur && cur->next != head){
        cout << cur->id;
        cur = cur->next;
    }
}   
int main(){


    return 0;
}