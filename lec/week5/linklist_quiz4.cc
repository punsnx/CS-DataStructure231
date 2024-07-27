#include<iostream>
using namespace std;
typedef struct _node
{
    int data;
    Node *next;
}Node;

typedef struct _header{
    int n;
    Node *first;
    Node *last;
}Header;

int main(){
    Header head;
    head.n = 0;
    head.first = NULL;
    head.last = NULL;

    Node first;
    first.data = 1;
    first.next = NULL;

    head.first = &first;
    head.last = &first;
    head.n++;

    Node second;
    second.data = 2;
    second.next = NULL;

    first.next = &second;
    head.last = &second;
    head.n++;
} 
// 6610402230 ศิริสุข ทานธรรม