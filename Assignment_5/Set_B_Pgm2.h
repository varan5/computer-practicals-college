#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *next, *prev;
} node;

void append(node *head)
{
    int n, count;
    node *last, *newnode;
    printf("How many nodes");
    scanf("%d", &n);
    last = head;
    for (count = 1; count <= n; count++)
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->next = newnode->prev = NULL;
        printf("\n enter the node data");
        scanf("%d", &newnode->info);
        newnode->next=head;
        newnode->prev=last;
        last->next=newnode;
        last=newnode;
        head->prev=newnode;
    }
}
void display(node *head)
{
    node *temp;
    printf("the elements are \n");
    for (temp = head->next; temp != head; temp = temp->next)
    {
        printf("%d\n", temp->info);
    }
}