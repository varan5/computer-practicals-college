#include"singlylist.h"
#include<stdio.h>
int main()
{
    node *head1=(node*)malloc(sizeof(node));
    node *head2=(node*)malloc(sizeof(node));
    node *head3=(node*)malloc(sizeof(node));
    create(head1);
    create(head2);
    printf("merging the list\n");
    merge(head1,head2,head3);
    display(head3);
}