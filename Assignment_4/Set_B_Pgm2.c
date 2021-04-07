#include<stdio.h>
#include "Set_B_Pgm2.h"

int main()
{
    node *head;
    head=(node *)malloc(sizeof(node));
    head->next=NULL;

    append(head);
    printf("the original list is:\n");
    display(head);
}
