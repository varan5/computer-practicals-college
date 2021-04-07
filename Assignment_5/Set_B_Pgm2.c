#include<stdio.h>
#include "Set_B_Pgm2.h"

int main()
{
    node *head;
    head=(node *)malloc(sizeof(node));
    head->next=head;
    head->prev=head;

    append(head);
    printf("the list is:\n");
    display(head);
}
