#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *next, *prev;
} node;

void append(node *head, int x)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *newnode=(node *)malloc(sizeof(node));
    newnode->info = x;
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = NULL;
}

void insert(node *head, int num, int pos)
{
    int i;
    node *temp, *temp1;
    for (temp = head, i = 1; (temp != NULL) && (i <= pos - 1); i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("\nout of range\n");
        return;
    }
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->info = num;
    newnode->next = newnode->prev = NULL;
    temp1 = temp->next;
    newnode->next = temp1;
    temp1->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}

int search(node *head, int x)
{
    int i;
    node *temp;
    for (temp = head->next, i = 1; temp!= NULL; i++, temp = temp->next)
    {
        if (temp->info == x)
            return i;
    }
    return 0;
}

void deletev(node *head, int x)
{
    node *temp, *temp1;
    for (temp = head; temp->next != NULL; temp = temp->next)
    {
        if (temp->next->info == x)
        {
            temp1 = temp->next;
            temp->next = temp1->next;
            if (temp1->next != NULL)
                temp1->next->prev = temp;
            free(temp1);
            return;
        }
    }
}

void deletep(node *head, int pos)
{
    int i;
    node *temp;
    for (temp = head, i = 1; (temp->next != NULL) && (i <= pos - 1); i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("\nout of range\n");
        return;
    }
    node *temp1 = temp->next;
    temp->next = temp1->next;
    if (temp1->next != NULL)
        temp1->next->prev = temp;
    free(temp1);
}

void display(node *head)
{
    node *temp;
    printf("the numbers are:\n");
    for (temp = head->next; temp!= NULL; temp = temp->next)
    {
        printf("%d\n", temp->info);
    }
}