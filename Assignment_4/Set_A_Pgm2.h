#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
    int info;
    struct node *next;
}node;
void create(node *head)
{
    int n,count;
    node *last,*newnode;
    printf("How many nodes");
    scanf("%d",&n);
    last=head;
    for(count=1;count<=n;count++)
    {
        newnode=(node*)malloc(sizeof(node));
        newnode->next=NULL;
        printf("\n enter the node data");
        scanf("%d",&newnode->info);
        last->next=newnode;
        last=newnode;
    }
}
void reverse(node *head)
{
    node *t1=head->next,*t2,*t3;
    if(t1==NULL)
        return;
    t2=t1->next;
    if(t2==NULL)
        return;
    t3=t2->next;
    t1->next=NULL;
    while(t3!=NULL)
    {
        t2->next=t1;
        t1=t2;
        t2=t3;
        t3=t3->next;
    }
    t2->next=t1;
    head->next=t2;
}
void display(node *head)
{
    node *temp;
    printf("the elements are:\n");
    for(temp=head->next;temp!=NULL;temp=temp->next)
    {
        printf("%d\n",temp->info);
    }
}
