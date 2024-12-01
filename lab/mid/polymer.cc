#include <iostream>
#include <sstream>
#include <string>
using namespace std;

typedef struct _Node{
    string name;
    double strength;
    _Node *next;
} Node;

Node *createNode(){
    Node *newNode = new Node;
    newNode->next = NULL;
    return newNode;
}

void addNodeSort(Node **head,string name,double strength){
    Node *newNode = createNode();
    newNode->name = name;
    newNode->strength = strength;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    Node *cur = *head,*prev = NULL;
    while(cur && cur->strength <= strength){
        prev = cur;
        cur = cur->next;
    }

    if(prev == NULL){
        newNode->next = cur;
        *head = newNode;
        return;
    }

    newNode->next = cur;
    prev->next = newNode;
}

void printList(Node *head){
    while(head){
        cout << head->name << " (" << head->strength << ") -> ";
        head = head->next;
    }
    cout << "None" << endl;

}
int main(){
    Node *head = NULL;
    string line;
    double totalBondStrength = 0;
    while(getline(cin,line)){
        istringstream in(line);
        string name;
        double strength;
        string tmp;
        getline(in,name,' ');
        getline(in,tmp,' ');
        strength = stod(tmp);
        addNodeSort(&head,name,strength);   
        totalBondStrength += strength;
    }
    cout << "Polymer Chain:" << endl;
    printList(head);
    cout << "Total Bond Strength: " << totalBondStrength << " + x," << endl
    << "when x is total bond strength in each monomers" << endl
    << "connected bonds" << endl;
}
