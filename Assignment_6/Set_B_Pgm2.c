#include"poly.h"
#include<stdio.h>
int main()
{
    node *head1=(node*)malloc(sizeof(node));
    node *head2=(node*)malloc(sizeof(node));
    node *head3=(node*)malloc(sizeof(node));
    node *head4=(node*)malloc(sizeof(node));
    node *head5=(node*)malloc(sizeof(node));
    
    create(head1);
    create(head2);
    printf("Adding the list\n");
    multiply(head1,head2,head3,head4);
    add(head3,head4,head5);
    display(head5);
}