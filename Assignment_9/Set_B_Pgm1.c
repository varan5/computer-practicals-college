#include<stdio.h>
#include"Set_B_Pgm1.h"

int main()
{
    int choice,num;
    init();
    do
    {
        printf("1.add\n");
        printf("2.remove\n");
        printf("3.peek\n");
        printf("4.isempty\n");
        printf("5.exit\n");
        printf("enter you choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
                printf("enter the number to be added\n");
                scanf("%d",&num);
                addq(num);
            break;

        case 2:
            if(isempty()==-1)
                printf("underflow\n");
            else
            {
                num=removeq();
                printf("the removed number is %d\n",num);
            }
            break;

        case 3:
           if(isempty()==-1)
                printf("underflow\n");
            else
            {
                num=peekq();
                printf("the peeked number is %d\n",num);
            }
            break;

        case 4:
            if(isempty()==-1)
                printf("the queue is empty\n");
            else
                printf("the queue is not empty\n");
            break;

        }
    }while(choice!=5);
}
