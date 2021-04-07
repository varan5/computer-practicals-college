#include<stdio.h>
#include "singlylist.h"

int main()
{
    node *head;
    head=(node *)malloc(sizeof(node));
    head->next=NULL;

    create(head);
    printf("the original list is:\n");
    display(head);
    reverse(head);
    printf("the reversed string is:\n");
    display(head);
}
