#include"poly.h"
#include<stdio.h>
int main()
{
    node *head1=(node*)malloc(sizeof(node));
    node *head2=(node*)malloc(sizeof(node));
    node *head3=(node*)malloc(sizeof(node));
    create(head1);
    create(head2);
    printf("Adding the list\n");
    add(head1,head2,head3);
    display(head3);
}