#include <iostream>
#include <sstream>
using namespace std;

typedef struct _Node {
    int data;
    _Node *next;
}Node;

typedef struct _HashCode {
    int hashCode;
    int n;
    Node *data;
    _HashCode *next;
}HashCode;

HashCode *createHashCode(){
    HashCode *newNode = new HashCode;
    newNode->n = 0;
    newNode->data = NULL;
    return newNode;
}
Node *createNode(){
    Node *newNode = new Node;
    newNode->next = NULL;
    return newNode;
}
HashCode* addHashCodeAscending(HashCode **head,int hashCode){
    HashCode *newNode = new HashCode;
    newNode->hashCode = hashCode;
    if(*head == NULL){
        *head = newNode;
        return newNode;
    }
    HashCode *cur = *head,*prev = NULL;
    while(cur && cur->hashCode < hashCode){
        prev = cur;
        cur = cur->next;
    }
    if(prev == NULL){
        newNode->next = *head;
        *head = newNode;
        return newNode;
    }
    newNode->next = cur;
    prev->next = newNode;
    return newNode;

}
void addDataNode(HashCode **head,int hashCode,int data,int &maxLenght){
    HashCode *curHash = *head;
    while(curHash && curHash->hashCode != hashCode){
        curHash=curHash->next;
    }
    if(curHash == NULL){
        curHash = addHashCodeAscending(head,hashCode);
    }
    Node **headNode = &curHash->data;

    Node *newNode = createNode();
    newNode->data = data;
    if(*headNode == NULL){
        *headNode = newNode;
        curHash->n++;

        if(curHash->n > maxLenght)maxLenght = curHash->n;
        return;
    }
    newNode->next = *headNode;
    *headNode = newNode;
    curHash->n++;
    if(curHash->n > maxLenght)maxLenght = curHash->n;
}

void addNodeAscending(Node **head,int data){
    Node * newNode = createNode();
    newNode->data = data;

    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node *cur = *head,*prev = NULL;
    while(cur && cur->data < data){
        prev = cur;
        cur=cur->next;
    }
    if(prev == NULL){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    newNode->next = cur;
    prev->next = newNode;
}
void addNode(Node **head,int data){
    Node * newNode = createNode();
    newNode->data = data;

    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node *cur = *head;
    while(cur && cur->next != NULL){
        cur=cur->next;
    }

    cur->next = newNode;
}
int calMedian(Node *listAscending,int n){
    double _n = n;
    int medPos;
    if(n % 2 == 0){//EVEN
        medPos = ((_n/2+(_n/2 + 1))/2);
    }else{//ODD
        medPos = ((_n+1)/2);
    }
    Node *cur = listAscending;
    for(int i = 0;i<medPos-1;i++){
        cur=cur->next;
    }
    return cur->data;
}

void printData(Node *head){
    Node *cur = head;
    while(cur){
        cout << cur->data;
        if(cur->next != NULL)cout << " ";
        cur = cur->next;
    }
}

void printHashTable(HashCode *head,int &expectLenght){
    HashCode *curHash = head;
    while(curHash){
        // cout << curHash->hashCode << ":  ";
        if(curHash->n == expectLenght){
            printData(curHash->data);
            cout << endl;
        }
        curHash = curHash->next;
    }
    
}

int main(){
    HashCode *hashTable = NULL;
    Node *listAscending = NULL;
    Node *list = NULL;

    int nData = 0;

    string line;
    getline(cin,line);
    istringstream inputStream(line);

    string str;
    while(getline(inputStream,str,' ')){
        int data = stoi(str);
        addNodeAscending(&listAscending,data);
        addNode(&list,data);
        nData++;
    }
    int key = calMedian(listAscending,nData);
    int maxLenght = 0;
    // cout << key << endl;

    Node *cur = list;
    while(cur){
        int data = cur->data;
        int remain = data % key;
        addDataNode(&hashTable,remain,data,maxLenght);
        cur = cur->next;
    }
    // cout << maxLenght << endl;
    printHashTable(hashTable,maxLenght);

}