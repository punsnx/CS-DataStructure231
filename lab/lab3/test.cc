#include <iostream>
using namespace std;

typedef struct _node
{
    int data;
    _node *next;
}node;

void copy(node *old,node *newList){
    size_t size = sizeof(*old);
    char *oldListNorm = (char *)old;
    char *newListNorm = (char *)newList;
    for(size_t i = 0;i<size;i++){
        newListNorm[i] = oldListNorm[i];
    }
} 
int main(){
    node a;
    a.data = 20;
    a.next = NULL;
    node b;
    cout << sizeof(a) <<endl;
    copy(&a,&b);
    cout << a.data << " " << a.next << endl;
    cout << b.data << " " << b.next << endl;
}