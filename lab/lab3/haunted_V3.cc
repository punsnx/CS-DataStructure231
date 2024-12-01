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
        cur->next = findNodeOrigin(head,cur->nextHand);
        cur->prev = findNodeOrigin(head,cur->prevHand);     
        cur = cur->_next;   
    }
}

void printList(Node *head){
    Node *cur = head;
    while(cur){
        cout << cur->origin;
        if(cur->_next != NULL)cout << " ";
        cur = cur->_next; 
    }
    cout << endl;
}

void printListConnect(Node *head){
    Node *cur = head;
    while(cur){
        cout << cur->origin;
        if(cur->_next != NULL)cout << " ";
        if(cur->next == head)break;
        cur = cur->next; 
    }
    cout << endl;
}

Node* copyList(Node *copyHead){
    Node *head = NULL;
    Node *cur=copyHead;
    while(cur){
        short origin = cur->origin;
        short nextHand = cur->nextHand;
        short prevHand = cur->prevHand;
        bool isSurvive = cur->isSurvive;
        addNode(&head,origin,nextHand,prevHand,isSurvive);
        cur=cur->_next;
    }
    return head;
}

void removeNode(Node **head,Node **refCur){
    Node *cur = *refCur;
    if(cur==NULL)return;
    if(cur==*head)*head=cur->next;
    Node *prev = cur->prev;
    prev->next = cur->next;
    cur->next->prev = prev;

    prev->nextHand = cur->next->origin;
    cur->next->prevHand = prev->origin;

    delete cur;
    *refCur = prev->next;
}

void calculateSurvivor(Node **head,short s,short x,short n,short m,short *count);

int main(){
    short n,m;
    cin >> n >> m;
    Node *head = NULL;
    for(short i = 0;i<n;i++){
        short left,right;
        cin >> left >> right;
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
    cout << endl;

    short startIdx;
    cin >> startIdx;

    // printList(head);
    // cout << "start : " << startIdx << endl;
    
    // PREPARE NODE TO CONNECT HAND
    initHandNode(head);
    // printListConnect(head);

    // cout << "MAIN PROGRAM" << endl;
    
    short count = 0;
    for(short i = 35 ;i <= 35;i++){
        Node *newHead = copyList(head);
        initHandNode(newHead);
        calculateSurvivor(&newHead,startIdx,i,n,m,&count);
    }
    if(count == 0)cout << "NOT POSSIBLE" << endl;
}
void calculateSurvivor(Node **head,short s,short x,short n,short m,short *count){
    bool finishFirstRound = false;
    // bool continueLoop = false;
    Node *cur=*head;
    for(short i = 0;i < s;i++){
        cur = cur->next;
    }
    if(m>=n)return;
    while(n > m){
        printListConnect(*head);

        // cout << finishFirstRound << endl;
        if(!finishFirstRound){
            removeNode(head,&cur);
        } else {
            for(short i = 0;i < x-1;i++){
                cur = cur->next;
                // if(cur==*head){
                //     continueLoop  = !continueLoop;
                //     break;
                // }
            }
            // if(continueLoop){
            //     continueLoop  = !continueLoop;
            //     finishFirstRound = !finishFirstRound;

            //     continue;
            // }
            removeNode(head,&cur);
        }
        --n;
        finishFirstRound = !finishFirstRound;
    }
    printListConnect(*head);
    short c = 0;
    Node *_cur = *head;
    while(_cur){
        if(_cur->isSurvive) c++;
        if(_cur->next == *head)break;
        _cur = _cur->next;
        
    }
    if(c==m) {
        // printListConnect(*head);
        (*count)++;
        cout << x << endl;
    }
    
}
// 0 1 2 3 4 5 6 7 8 9
// 1 2 3 4 5 6 7 8 9

// 1 2 3 4 5 6 7 9
// 1 2 3 4 5 6 7

// 1 2 3 4 5 6 
// 2 3 4 5 6 

// 2 3 4 5





