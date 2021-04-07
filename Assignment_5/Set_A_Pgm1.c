#include<stdio.h>
#include "Set_A_Pgm1.h"

int main()
{
    node * head;
    head=(node *)malloc(sizeof(node));
    head->next=NULL;
    head->prev=NULL;
    int num,pos;
    int choice;
    do
    {
        printf("1:append\n");
        printf("2:insert\n");
        printf("3:search\n");
        printf("4:delete by number\n");
        printf("5:delete by position\n");
        printf("6:display\n");
        printf("7:exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter the number\n");
            scanf("%d",&num);
            append(head,num);
            break;

        case 2:
            printf("enter the number\n");
            scanf("%d",&num);
            printf("enter the position\n");
            scanf("%d",&pos);
            insert(head,num,pos);
            break;

        case 3:
            printf("enter the number\n");
            scanf("%d",&num);
            int j=search(head,num);
            if(j==0)
                printf("number not found\n");
            else
                printf("number found at position %d\n",j);
            break;

        case 4:
            printf("enter the number\n");
            scanf("%d",&num);
            deletev(head,num);
            break;

        case 5:
            printf("enter the position\n");
            scanf("%d",&pos);
            deletep(head,pos);
            break;

        case 6:
            display(head);
            break;
        }
    }while(choice!=7);
}
