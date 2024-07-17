#include <iostream>
using namespace std;

typedef struct _node
{
    short id;
    _node *next;
}node;

void addNode(node **head,short data){//QUEUE LINKLIST
    node *newNode = new node;
    newNode->id = data;
    newNode->next = NULL;
    if(*head==NULL){
        *head = newNode;
        return;
    }
    node *cur=*head;
    while(cur->next){
        cur = cur->next;
    }
    cur->next = newNode;
}
void printList(node *head){
    node *cur=head;
    while(cur){
        cout << cur->id;;
        cur = cur->next;
        if(cur) cout << " ";
    }cout << endl;
}

bool removeNodeIdx(node **head,short idx){
    node *cur=*head,*prev=NULL;
    while(cur){
        if(idx<=0)break;
        prev = cur;
        cur = cur->next;
        --idx;
    }
    if(cur==NULL && prev == NULL){//*head == NULL
        return 0;
    }
    if(cur == NULL && prev){
        return 0;
    }
    if(cur && prev == NULL){
        *head = cur->next;
        delete cur;  
        return 1; 
    }
    prev->next = cur->next;
    delete cur;

    return 1;
}
int main(){
    node *head = NULL;
    node *surv = NULL;
    short n,m,left,right,s;
    cin >> n >> m;
    for(short i = 0;i<n;i++){
        addNode(&head,i);
        cin >> left >> right;
    }
    for(short i = 0;i<m;i++){
        short tmp;
        cin >> tmp;
        addNode(&surv,tmp);
    }
    cin >> s;
    cout << "BASE : ";
    printList(head);
    for(short x = 4;x<=4;x++){
        short count = 0;
        short round = 0;
        short actualIdx = s-x;
        while(true){
            actualIdx = actualIdx + x - count;
            cout << "A" << actualIdx << " : ";
            bool canRemS = removeNodeIdx(&head,actualIdx);
            printList(head);
            if(round == 0 && !canRemS){
                break;
            }else if(round > 0 && !canRemS){
                actualIdx = s-x;
                count = 0;
                round = 0;
                continue;
            }
            round++;
            count = 1;
        }

    }
    // printList(head);
    // printList(surv);
    return 0;
}