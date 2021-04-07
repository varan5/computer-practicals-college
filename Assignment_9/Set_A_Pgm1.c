#include<stdlib.h>
#include<stdio.h>
#include "Set_A_Pgm1.h"
int main()
{
    int choice, data;
    QUEUE pq;
    initQueue(&pq);
    do
    {
        printf("\n1:PUSH\n2:POP\n3:PEEK\n4:EXIT");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            if (isFull(&pq))
                printf("\n Queue Overflow");
            else
            {
                printf("\n Enter the element: ");
                scanf("%d", &data);
                addq(&pq, data);
            }
            break;
        case 2:
            if (isEmpty(&pq))
                printf("\n Queue Underflow");
            else
                printf("\n The element is: %d", removeq(&pq));
            break;
        case 3:
            if (isEmpty(&pq))
                printf("\n Queue Underflow");
            else
                printf("\n The element is: %d", peek(&pq));
            break;
        }
    } while (choice != 4);
    return 0;


}