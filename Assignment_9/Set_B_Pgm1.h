#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} node;

node *front, *rear;

void init()
{
    front = rear = NULL;
}

void addq(int num)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->info = num;
    if (front == NULL)
    {
        front = rear = newnode;
        front->next = NULL;
    }
    else
    {
        newnode->next=NULL;
        rear->next = newnode;
        rear = newnode;
    }
}

int removeq()
{
    int num;
    node *temp;
    temp = front;
    num = front->info;
    front = front->next;
    free(temp);
    // front=NULL;
    return num;
}

int peekq()
{
    int num = front->info;
    return num;
}

int isempty()
{
    if (front == NULL)
        return -1;
    else
        return 1;
}
