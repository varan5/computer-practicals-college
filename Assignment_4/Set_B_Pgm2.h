#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

void append(node *head)
{
    int num;
    node *last;
    printf("enter the number of nodes:\n");
    scanf("%d",&num);
    last=head;
    for(int i=0;i<num;i++)
    {
        node *newnode;
        newnode=(node *)malloc(sizeof(node));
        printf("enter the data:\n");
        scanf("%d",&newnode->data);
        newnode->next=head;
        last->next=newnode;
        last=newnode;
    }

}
void display(node *head)
{
    node *temp;
    printf("the elements are:\n");
    for(temp=head->next;temp!=head;temp=temp->next)
    {
        printf("%d\n",temp->data);
    }
}