#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int info;
    struct node *next, *prev;
} node;

void insert(node *head, int x)
{
    node *current;

    node *newnode = (node *)malloc(sizeof(node));
    newnode->info = x;
    if (head->next == NULL)
    {
        head->next = newnode;
        newnode->prev = head->next;
        newnode->next = NULL;
    }

    else
    {
        current = head;
        while (current->next != NULL &&
               current->next->info < newnode->info)
            current = current->next;

        newnode->next = current->next;

        if (current->next != NULL)
            newnode->next->prev = newnode;

        current->next = newnode;
        newnode->prev = current;
    }
}

int search(node *head, int x)
{
    int i;
    node *temp;
    for (temp = head->next, i = 1; temp != NULL; i++, temp = temp->next)
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