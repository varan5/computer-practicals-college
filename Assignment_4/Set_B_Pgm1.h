#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int info;
    struct node *next;
} node;

void insert(node *head, int x)
{
    struct node *temp=head,*newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->info=x;
    if(temp==NULL)
    {
        temp->next=newnode;

    }else {  
        while (temp->next != NULL 
               && temp->next->info < x) { 
            temp = temp->next; 
        } 
        newnode->next = temp->next; 
        temp->next = newnode; 
    } 
    
}

int search(node *head, int x)
{
    int i;
    node *temp;
    for (temp = head->next, i = 1; temp->next != NULL; i++, temp = temp->next)
    {
        if (temp->info == x)
            return i;
    }
    return 0;
}

void display(node *head)
{
    node *temp;
    printf("the elements are:\n");
    for (temp = head->next; temp != NULL; temp = temp->next)
    {
        printf("%d\n", temp->info);
    }
}