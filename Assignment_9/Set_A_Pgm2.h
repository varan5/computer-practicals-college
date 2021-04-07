#include <stdlib.h>
#include <stdio.h>
typedef struct Queue
{
    int info;
    struct Queue *next;
} NODE;
NODE *rear;
void initQueue()
{
    rear = NULL;
}
int isEmpty()
{
    return rear == NULL;
}
void addq(int num)
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = num;
    if (rear == NULL)
    {
        rear=newnode;
        rear->next = rear;
    }else{
        newnode->next=rear->next;
        rear->next=newnode;
        rear=newnode;
    }
}
int removeq()
{
    NODE* front=rear->next;
    int num=front->info;
    if(rear->next==rear)
    {
        free(rear);
        rear=NULL;
    }else{
        rear->next=front->next;
        free(front);
        // front=NULL;
    }
    return num;
}
int peek()
{
    return rear->next->info;
}