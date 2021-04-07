#include<stdio.h>
#include "Set_A_Pgm2.h"

int main()
{
    node *head;
    head=(node *)malloc(sizeof(node));
    head->next=NULL;

    create(head);
    printf("the original list is:\n");
    display(head);
    reverse(head);
    printf("the reversed list is:\n");
    display(head);
}
