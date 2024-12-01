#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node
{
    int data;
    struct _Node *next;
} Node;

void addNode(Node **head, int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *cur = *head, *prev = NULL;
    while (cur)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = newNode;
}

int main()
{
    int n = 0;
    Node *head = NULL;
    char string[100];
    while (scanf("%s", string) != EOF)
    {
        if(string=="-1")printf("true");
        printf("%s\n", string);
    }
}