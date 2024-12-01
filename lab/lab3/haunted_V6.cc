#include <iostream>
using namespace std;
typedef struct _node
{
    short origin;
    short nextHand;
    short prevHand;
    bool isSurvive;
    //keep input node
    _node *_next;
    //connect hand
    _node *next;
    _node *prev;
    _node *nextRef;
    _node *prevRef;
}Node;

void addNode(Node **head,short o,short nH,short pH,bool isSurvive){
    Node *newNode = new Node;
    newNode->origin = o;
    newNode->nextHand = nH;
    newNode->prevHand = pH;
    newNode->isSurvive = isSurvive;
    newNode->_next = NULL;
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->nextRef = NULL;
    newNode->prevRef = NULL;
    if(*head == NULL){
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
    return cur;
}

void initHandNode(Node *head){
    Node *cur=head;
    while(cur){
        cur->nextRef = findNodeOrigin(head,cur->nextHand);
        cur->prevRef = findNodeOrigin(head,cur->prevHand);     
        // cout << cur->prevRef << " " << cur->origin << " " << cur->nextRef << endl;
        cur = cur->_next;   
    }
}
void initHandNodeMap(Node *head){
    Node *cur=head;
    while(cur){
        cur->next = cur->nextRef;
        cur->prev = cur->prevRef;
        cur = cur->_next;   
    }
}

void removeNodeFake(Node **head,Node **refCur){
    Node *cur = *refCur;
    if(cur==NULL)return;
    if(cur==*head)*head=cur->next;
    Node *prev = cur->prev;
    prev->next = cur->next;
    cur->next->prev = prev;

    // prev->nextHand = cur->next->origin;
    // cur->next->prevHand = prev->origin;

    // delete cur;
    *refCur = cur->next;
}

void calculateSurvivor(Node **head,short s,short x,short n,short m,short *count);

bool isInRange(short n,short min,short maxBound){
    if(n < min || n >= maxBound)return false;
    return true;
}

int main(){
    short n,m;
    cin >> n >> m;
    Node *head = NULL;
    bool handOutOfRange = false;
    for(short i = 0;i<n;i++){
        short left,right;
        cin >> left >> right;
        // handOutOfRange n
        if(!isInRange(left,0,n) || !isInRange(right,0,n))handOutOfRange=true;

        addNode(&head,i,left,right,false);
    }
    // cout << "survivors : ";
    for(short i = 0;i<m;i++){
        short survivorOrigin;
        cin >> survivorOrigin;
        Node *survivor = findNodeOrigin(head,survivorOrigin);
        survivor->isSurvive = true;
        // cout << survivor->origin << " ";
    }
    // cout << endl;

    short startIdx;
    cin >> startIdx;
    
    // cout << "MAIN PROGRAM" << endl;
    if(handOutOfRange || m>=n){
        cout << "NOT POSSIBLE" << endl;
        return 0;
    }
    initHandNode(head);

    short count = 0;
    for(short i = 0 ;i <= 1000;i++){

        Node *newHead = head;
        initHandNodeMap(newHead);
        calculateSurvivor(&newHead,startIdx,i,n,m,&count);

    }
    
    if(count == 0)cout << "NOT POSSIBLE" << endl;
    return 0;
}
void calculateSurvivor(Node **head,short s,short x,short n,short m,short *count){
    Node *cur=*head;
    for(short i = 0;i < s;i++){
        if(cur && cur->next == NULL)return;
        cur = cur->next;
    }
    while(n > m){

        for(short i = 0;i < x;i++){
            if(cur && cur->next == NULL)return;
            cur = cur->next;
        }
        if(cur->isSurvive){
            return;
        }
        if(cur && cur->next == NULL)return;
        removeNodeFake(head,&cur);

        --n;

    }
    (*count)++;
    cout << x << endl;
    
}

// 0 1 2
// 1 2

// 0 1 2
// 0 1
// 0
