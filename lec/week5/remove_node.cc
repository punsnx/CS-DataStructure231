#include<iostream>
using namespace std;

typedef struct _node
{
    int data;
    _node *next;
}Node;

typedef struct link_list
{
    int length;
    Node *head;
} NumList;

Node *newNode(){
    Node *p;
    p = new Node;
    p->next = NULL;
    return p;
}

void initList(NumList *n){
    n->head = NULL;
}

void deleteHeadList(NumList *nl){
    Node *temp;
    temp = nl->head;
    nl->head = temp->next;
    delete temp;
}
void removeNode(NumList *linkList,int data){
    Node *head =linkList->head;
    
    if(head == NULL)return;
    Node *cur=head,*prev=NULL;
    while(cur && cur->data != data){
        prev=cur;
        cur = cur->next;
    }
    if(head && prev == NULL){
        deleteHeadList(linkList);
        return;
    }
    if(prev && cur == NULL){
        return;
    }
    prev->next = cur->next;
    delete cur;

}
void appendHeadList(NumList *s, Node *p){
    if (s->head == NULL){
        s->head = p;	
	} else { // s->head != NULL
		p->next = s->head;
		s->head = p;
	}
}

void printNumList(NumList L){
     Node *pCurr = L.head;

	 while (pCurr != NULL){
		printf("Num: %d\n", pCurr->data);
		pCurr = pCurr->next;
	 }
}

int main() {
   NumList NL;
   Node *N;
   initList(&NL);
   for (int i = 0; i < 3; ++i){
      N     = newNode();
      N->data = i;
      appendHeadList(&NL,N);
   }

   printNumList(NL);
   cout << endl;
//    removeNode(&NL,2);
   removeNode(&NL,1);
//    removeNode(&NL,0);
   printNumList(NL);
   return 0;
}