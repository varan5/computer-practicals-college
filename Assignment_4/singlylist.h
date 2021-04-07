#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
    int info;
    struct node *next;
}node;

void append(node *head,int x)
{
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    temp->next=newnode;
    newnode->info=x;
    newnode->next=NULL;
}

void insert(node *head,int x,int pos)
{
    int i;
    node *temp;
    for(temp=head,i=1;(temp!=NULL)&&(i<=pos-1);i++)
    {
        temp=temp->next;
    }
    if(temp==NULL)
            {
                printf("\nout of range\n");
                return;
            }
    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->info=x;
}

int search(node *head,int x)
{
    int i;
    node *temp;
    for(temp=head->next,i=1;temp->next!=NULL;i++,temp=temp->next)
    {
        if(temp->info==x)
        return i;
    }
    return 0;
}

void deletep(node *head,int x)
{
    int i;
    node *temp,*temp1;
    for(temp=head,i=1;temp->next!=NULL;i++,temp=temp->next)
    {
        if(temp->next->info==x)
        {
           temp1=temp->next;
           temp->next=temp1->next;
           free(temp1);
           return;
        }
    }
}

void deletel(node *head,int pos)
{
    int i;
    node *temp;
    for(temp=head,i=1;(temp->next!=NULL)&&(i<=pos-1);i++)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
           {
               printf("\nout of range\n");
               return;
           }
    node *temp1=temp->next;
        temp->next=temp1->next;
        free(temp1);
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