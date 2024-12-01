#include <iostream>
using namespace std;

typedef struct _Node {
    string color;
    int count;
    _Node *next;
} Node;

Node *createNode(){
    Node *newNode = new Node;
    newNode->next = NULL;
    return newNode;
}
void addNode(Node **head,string color){
    Node *newNode = createNode();
    newNode->color = color;
    newNode->count = 0;

    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node *cur = *head,*prev = NULL;
    while(cur && cur->color != color){
        prev = cur;
        cur=cur->next;
    }
    if(cur == NULL){
        prev->next = newNode;
        return;
    }
    delete newNode;
    cur->count++;
}

void printList(Node *list){
    while(list){
        cout << list->count; 
        if(list->next != NULL)cout << " ";
        list = list->next;
    }
    cout << endl;

}

void spectroCombustion(Node **chemReact,double m,string color){
    // cout << m << " " << color << endl;
    if(m <= 1){
        if(color != "Nocolor" && m > 0)addNode(chemReact,color);
        return;
    }else if (color == "Nocolor"){
        spectroCombustion(chemReact,m-1,"Emerald");
    }else if(color == "Emerald"){
        if(m <= 20){
            spectroCombustion(chemReact,m-1,"Amber");
        }else if (m <= 50){
            spectroCombustion(chemReact,m*0.80,"Aquamarine");
        }else {
            spectroCombustion(chemReact,m*0.50,"Amethyst");
        }
    }else if(color == "Amethyst"){
        spectroCombustion(chemReact,m*0.70,"Aquamarine");
        spectroCombustion(chemReact,m*0.30,"Emerald");
    }else if(color == "Aquamarine"){
        if(m >= 100){
            spectroCombustion(chemReact,m*0.90,"Amber");
        }else{
            spectroCombustion(chemReact,m-10,"Amethyst");
        }
    }else if(color == "Amber"){
        spectroCombustion(chemReact,m*0.10,"Emerald");
        spectroCombustion(chemReact,m*0.15,"Amethyst");
        spectroCombustion(chemReact,m*0.25,"Aquamarine");
    }
    if(color != "Nocolor")addNode(chemReact,color);
}

int main(){
    Node *chemReact = NULL;
    addNode(&chemReact,"Emerald");
    addNode(&chemReact,"Amethyst");
    addNode(&chemReact,"Aquamarine");
    addNode(&chemReact,"Amber");

    double mass;
    cin >> mass;

    spectroCombustion(&chemReact, mass, "Nocolor");
    printList(chemReact);

    

    


}