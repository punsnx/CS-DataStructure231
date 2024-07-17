#include <iostream>
using namespace std;

typedef struct _node
{
    short data;
    _node *next;
}node;

void addNodeStack(node **head,short data){//LAST IN FIRST OUT
    node *newNode = new node;
    newNode->next = NULL;
    newNode->data = data;
    if(*head==NULL){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

void printList(node *head){
    node *cur = head;
    while(cur){
        cout << cur->data;
        if(cur->next){//ADD SPACE
            cout << " ";
        }
        cur = cur->next;
    }
    cout << endl;
}

int isInList(node *head,short n){
    node *cur=head;
    int iter = 0;
    while(cur){
        ++iter;
        if(cur->data==n)return iter;
        cur = cur->next;
    }
    return 0;
}
void insertNodeIdx(node **head,int idx,short data){
    node *newNode= new node;
    newNode->data = data;
    newNode->next = NULL;
    if(*head==NULL){//IMPOSSIBLE IF NULL BASELIST NO INTERSECT MEMBER
        *head = newNode;
        return;
    }
    node *cur=*head,*prev=NULL;
    for(int i = 0;i<idx;i++){
        prev = cur;
        cur = cur->next;
    }
    newNode->next = cur;
    prev->next = newNode;
    
}
void combineLine(node **baseHead,node *checkHead,int inIdx){
    // cout << "inIdx : " << inIdx << endl;
    // LOOP checkList
    node *cur=checkHead;//from 2nd index
    while(cur){
        int _inIdx = isInList(*baseHead,cur->data);
        if(!_inIdx){
            insertNodeIdx(baseHead,inIdx,cur->data);
            ++inIdx;
        }
        cur=cur->next;
    }
}
int main(){
    node *baseList = NULL,*checkList = NULL;
    short n;
    cin >> n;

    for(short i = 0;i<n;i++){
        short prev=0;
        checkList=NULL;

        while(true){
            short d;
            cin >> d;
            if(d==0 && i==0)break;
            if(d==0 && i > 0){
                int inIdx = isInList(baseList,prev);
                if(!inIdx)break;
                // cout << prev;
                combineLine(&baseList,checkList->next,inIdx);
                break;
            }
            if(i==0)addNodeStack(&baseList,d);
            else addNodeStack(&checkList,d);
            prev = d;
        }
    }
    printList(baseList);
    return 0;
}