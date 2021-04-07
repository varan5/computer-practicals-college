#include<stdio.h>
#include "Set_B_Pgm1.h"

int main()
{
    node * head;
    head=(node *)malloc(sizeof(node));
    head->next=NULL;
    int num,pos;
    int choice;
    do
    {
        printf("1:insert\n");
        printf("2:search\n");
        printf("3:display\n");
        printf("4:exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter the number\n");
            scanf("%d",&num);
            insert(head,num);
            break;

        case 2:
            printf("enter the number\n");
            scanf("%d",&num);
            printf("position is %d\n",search(head,num));
            break;

        case 3:
            display(head);
            break;
        }
    }while(choice!=4);
}
