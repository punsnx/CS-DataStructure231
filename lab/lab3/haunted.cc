#include <iostream>
using namespace std;

typedef struct _node
{
    short origin;
    bool isSurvive;
    // Hand Link Origin
    short nextHand;
    short prevHand;
    // Hand Link Reference Pointer
    _node *nextRef;
    _node *prevRef;
    // Iterate Link Pointer
    _node *next;
    _node *prev;
    // Linear NEXT Pointer
    _node *_next;
}Node;
Node* _newNode(short origin,short nextHand,short prevHand){
    Node *newNode = new Node;
    newNode->origin = origin;
    newNode->isSurvive = false;
    newNode->nextHand = nextHand;
    newNode->prevHand = prevHand;

    newNode->nextRef = NULL;
    newNode->prevRef = NULL;

    newNode->next = NULL;
    newNode->prev = NULL;

    newNode->_next = NULL;

    return newNode;
}

void addNode(Node **head,short o,short nH,short pH){
    Node *newNode = _newNode(o,nH,pH);
    if(*head==NULL){
        *head = newNode;
        return;
    }
    Node *cur=*head,*prev=NULL;
    while(cur){
        prev=cur;
        cur=cur->_next;
    }
    prev->_next = newNode;
}

Node* findNodeOrigin(Node *head, short origin){
    if(head==NULL)return NULL;
    Node *cur = head;
    while(cur && cur->origin != origin ){
        cur = cur->_next;
    }
    return cur;//NULL IF NOT FOUND
}

void initHandNode(Node *head){
    Node *cur = head;
    while(cur){
        cur->nextRef = findNodeOrigin(head,cur->nextHand);
        cur->prevRef = findNodeOrigin(head,cur->prevHand);
        cur = cur->_next;
    }
}

void _initHandNode(Node *head){
    Node *cur = head;
    while(cur){
        cur->next = cur->nextRef;
        cur->prev = cur->prevRef;
        cur = cur->_next;
    }
}

void printList(Node *head){
    Node *cur=head;
    if(head==NULL)return;
    while(cur){
        cout <<cur->origin;
        if(cur->_next!=NULL)cout << " ";
        cur = cur->_next;
    }
    cout << endl;
}

void printCircularList(Node *head){
    Node *cur=head;
    if(head==NULL)return;
    while(cur){
        cout <<cur->origin;
        if(cur->_next!=NULL)cout << " ";
        if(cur->next==head)break;
        cur = cur->next;
    }
    cout << endl;
}

void calSurvivor(Node **head,short n, short m,short s,short x,short *c);

bool removeNodeFake(Node **head,Node **refCur);

bool isValidCircle(Node **head,short n){
    Node *curNext=*head;
    short cNext = 0;
    while(curNext){
        ++cNext;
        curNext=curNext->nextRef;
        if(curNext==*head)break;
    }
    Node *curPrev=*head;
    short cPrev = 0;
    while(curPrev){
        ++cPrev;
        curPrev=curPrev->prevRef;
        if(curPrev==*head)break;
    }
    if((curNext == *head && curPrev == *head) && (cNext == n && cPrev == n))return true;
    return false;
}
int main(){
    // INPUT
    short n,m;
    cin >> n >> m;
    Node *head = NULL;
    for(short i=0;i<n;i++){
        short left,right;
        cin >> left >> right;
        addNode(&head,i,left,right);
    }
    for(short i=0;i<m;i++){
        short survivorIdx;
        cin >> survivorIdx;
        Node *survivor = findNodeOrigin(head,survivorIdx);
        if(survivor)survivor->isSurvive = true;
    }
    short startIdx;
    cin >> startIdx;
    // MAIN PROGRAM
    initHandNode(head);

    short count = 0;
    if(isValidCircle(&head,n)){
        for(short x = 0;x <= 1000;x++){
            Node *newHead = head;
            _initHandNode(newHead);
            // printCircularList(newHead);
            calSurvivor(&newHead,n,m,startIdx,x,&count);
        }
    }
    if(count == 0)cout << "NOT POSSIBLE" << endl;
    return 0;
}
bool removeNodeFake(Node **head,Node **refCur){
    Node *cur=*refCur;
    if(cur==NULL)return false;
    Node *prev = cur->prev;
    Node *next = cur->next;
    if(cur==*head)*head=next;
    prev->next = next;
    next->prev = prev;

    *refCur = next;
    return true;
}

void calSurvivor(Node **head,short n, short m,short s,short x,short *c){
    Node *cur = *head;
    // Shift Start Index
    for(short i = 0;i < s;++i){
        cur = cur->_next;
    }
    while(n > 0){
        // printCircularList(*head);
        // Shift x
        for(short i = 0;i < x;++i){
            cur = cur->next;
        }
        // now cur is remove idx
        if(cur->isSurvive)return;
        if(removeNodeFake(head,&cur))--n;
        if(n<=m)break;
    }
    // printCircularList(*head);
    (*c)++;
    cout << x << endl;

}