#include <iostream>
#include <stack>
#include <queue>
using namespace std;

typedef struct _queue{
    short number;
    string name;
    _queue *next;
}Queue;

typedef struct _hasteNode {
    short haste;
    Queue *queue;
    _hasteNode *next;
}HasteNode;

Queue* newQueue(short number,string name){
    Queue *newNode = new Queue;
    newNode->number = number;
    newNode->name = name;
    newNode->next = NULL;
    return newNode;
}

void addQueue(Queue **head,short number,string name){
    Queue *newNode = newQueue(number,name);
    if(*head == NULL){
        *head=newNode;
        return;
    }
    Queue *cur=*head,*prev=NULL;
    while(cur){
        prev=cur;
        cur=cur->next;
    }
    prev->next = newNode;
}

HasteNode* findHasteQueue(HasteNode *head,short haste){
    HasteNode *cur = head;
    while(cur && cur->haste != haste){
        cur=cur->next;
    }
    return cur;
}
HasteNode* newHasteNode(short haste){
    HasteNode *newNode = new HasteNode;
    newNode->haste = haste;
    newNode->queue = NULL;
    newNode->next = NULL;
    return newNode;
}
void addHasteQueue(HasteNode **head,short haste,short queueNuber,string name){
    HasteNode *haveHasteQueue = findHasteQueue(*head,haste);
    if(haveHasteQueue){
        addQueue(&haveHasteQueue->queue,queueNuber,name);
        return;
    }
    HasteNode *newNode = newHasteNode(haste);
    addQueue(&newNode->queue,queueNuber,name);
    if(*head==NULL){
        *head = newNode;
        return;
    }

    HasteNode *cur = *head,*prev=NULL;
    while(cur && cur->haste > haste){//NO POP =
        prev = cur;
        cur = cur->next;
    }

    if(cur && prev == NULL){
        newNode->next = *head;  
        *head = newNode;
        return;
    }
    newNode->next = cur;
    prev->next = newNode;


}
void printHasteQueue(HasteNode *head,short m){
    HasteNode *cur=head;
    while(cur && m > 0){
        Queue *curQ = cur->queue;
        while(curQ && m > 0){
            cout << curQ->name << endl;
            --m;
            curQ = curQ->next;
        }
        cur = cur->next;   
    }
}
int main(){
    short n,m;
    cin >> n >> m;
    if(m==0)return 0;
    HasteNode *hasteQueue = NULL;
    for(short i = 0;i < n;i++){
        short h;string name;
        cin >> h >> name;
        addHasteQueue(&hasteQueue,h,i,name);
    }
    printHasteQueue(hasteQueue,m);
    return 0;
}