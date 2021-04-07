#include<stdio.h>
#include "Set_A_Pgm2.h"
int main()
{
    int choice, data;
    NODE pq;
    initQueue();
    do
    {
        printf("\n1:PUSH\n2:POP\n3:PEEK\n4:EXIT");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
                printf("\n Enter the element: ");
                scanf("%d", &data);
                addq(data);
            break;
        case 2:
            if (isEmpty(&pq))
                printf("\n Stack Underflow");
            else
                printf("\n The element is: %d", removeq(&pq));
            break;
        case 3:
            if (isEmpty(&pq))
                printf("\n Stack Underflow");
            else
                printf("\n The element is: %d", peek(&pq));
            break;
        }
    } while (choice != 4);
    return 0;


}