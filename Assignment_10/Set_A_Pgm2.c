#include<stdlib.h>
#include<stdio.h>
#include "Set_A_Pgm2.h"
int main()
{
    int choice, data;
    QUEUE pq;
    init(&pq);
    do
    {
        printf("\n1:ADDL\n2:ADDR\n3:REMOVEL\n4:REMOVER\n5:EXIT");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
                printf("\n Enter the element: ");
                scanf("%d", &data);
                insertLeft(&pq, data);
            break;
        case 2:
                printf("\n Enter the element: ");
                scanf("%d", &data);
                insertRight(&pq, data);
            break;
            
        case 3:
            if (isEmpty(&pq))
                printf("\n Queue Underflow");
            else
                printf("\n The element is: %d", removeLeft(&pq));
            break;
        case 4:
            if (isEmpty(&pq))
                printf("\n Queue Underflow");
            else
                printf("\n The element is: %d", removeRight(&pq));
            break;
        }
    } while (choice != 5);
    return 0;


}