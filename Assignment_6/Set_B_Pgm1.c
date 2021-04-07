#include"singlylist.h"
#include<stdio.h>
int main()
{
    node *head=(node*)malloc(sizeof(node));
    create(head);
    printf("Sorting the list\n");
    sortList(head);
    display(head);
}