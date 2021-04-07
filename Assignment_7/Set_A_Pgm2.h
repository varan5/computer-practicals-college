#include <stdio.h>
#include <malloc.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;
NODE *top;
void initStack() { top = NULL; }
void push(int data)
{
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->next = top;
    top = newnode;
}
int pop()
{
    NODE *tmp=top;
    int data;
    tmp->data = top->data;
    top = top->next;
    data = tmp->data;
    free(tmp);
    return data;
}
int peek() { return top->data; }
int isEmpty() { return top == NULL; }