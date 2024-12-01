#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef struct _Node{
    string name;
    string houseNo;
    _Node *next;
}Node;

Node *createNode(){
    Node *newNode = new Node;
    newNode->next = NULL;
    return newNode;
}

void addNodeHead(Node **head,Node **tail,string name,string houseNo){
    Node * newNode = createNode();
    newNode->name = name;
    newNode->houseNo = houseNo;

    if(*head == NULL){
        *head = newNode;
        *tail = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}
void addNode(Node **head,string name,string houseNo){
    Node * newNode = createNode();
    newNode->name = name;
    newNode->houseNo = houseNo;

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
string search(Node *head,Node *tail,string name,int n){
    int l = 1;
    int r = n;
    int midIdx = (l+r)/2;

    bool end = false;    
    while(!end){
        if(midIdx == l && !end){
            end = true;
        }
        
        int move = midIdx - l;
        Node *mid = head;
        for(int i = 0;i<move;i++){
            mid = mid->next;
        }



        if(mid->name == name){
            return mid->houseNo;
        }else if(mid->name > name){
            if(head->name == name){
                return head->houseNo;
            }else {
                tail = mid;
                r = midIdx;
            }
        }else {
            if(tail->name == name){
                return tail->houseNo;
            }else {
                head = mid;
                l = midIdx;
            }
        }
        midIdx = (l+r)/2;
    }
    return "Contact not found.";

}

int main(){
    Node *addressBook = NULL;
    Node *tail = NULL;
    Node *searchList = NULL;
    string line;
    int n = 0;
    while(getline(cin,line)){
        size_t hyphenPos = line.find('-');
        if(hyphenPos != string::npos){
            break;
        }
        istringstream inputStream(line);
        string name; getline(inputStream,name,' ');
        string houseNo; getline(inputStream,houseNo,' ');
        addNodeHead(&addressBook,&tail,name,houseNo);
        n++;
    }
    while(getline(cin,line)){
        // addNode(&searchList,line,"0");
        cout << search(addressBook,tail,line,n) << endl;
    }
    // Node *cur = searchList;
    // while(cur){
    //     cout << search(addressBook,tail,cur->name,n) << endl;
    //     cur = cur->next;
    // }

}