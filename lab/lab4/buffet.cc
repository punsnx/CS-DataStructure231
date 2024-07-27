#include<iostream>
using namespace std;

typedef struct _node {
    short hunger;
    string name;
    _node *less;
    _node *high;
}Node;
void addNode(Node **head,short hunger,string name){
    Node *newNode = new Node;
    newNode->hunger = hunger;
    newNode->name = name;
    newNode->less = NULL;
    newNode->high = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node *cur = *head,*prev=NULL;
    while(cur){
        prev = cur;
        if(hunger < cur->hunger){
            cur = cur->less;
        }else{
            cur = cur->high;
        }
    }
    if(hunger < prev->hunger){
        prev->less = newNode;
    }else{
        prev->high = newNode;
    }
}

string selectCustomer(Node **head){
    Node *cur = *head,*prev=NULL,*prev1;
    string name;
    if(cur==*head && (!cur->less && !cur->high)){  
        name = cur->name; 
        *head= NULL;delete cur;
        return name;
    }
    while (cur){
        prev = cur;
        if(cur->high){
            cur = cur->high;
        }else{
            name = cur->name;
            prev->high = cur->less;
            delete cur;
            return name;
        }
    }
    name = prev->name;
    return name;
    
}
int main(){
    short n,m;
    cin >> n >> m;
    Node *head = NULL;
    for(short i = 0;i<n;i++){
        short hunger;
        string name;
        cin >> hunger >> name;
        addNode(&head,hunger,name);
    }
    if(m==0)return 0;
    short count = (n > m ? m : n);

    for(short i = 0;i<count;i++){
        cout << selectCustomer(&head) << endl;
    }

}