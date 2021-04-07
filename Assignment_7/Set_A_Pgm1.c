#include "Set_A_Pgm1.h"
#include <stdio.h>
int main()
{
    int choice, data;
    STACK s;
    initStack(&s);
    do
    {
        printf("\n1:PUSH\n2:POP\n3:PEEK\n4:EXIT");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            if (isFull(&s))
                printf("\n Stack Overflow");
            else
            {
                printf("\n Enter the element: ");
                scanf("%d", &data);
                push(&s, data);
            }
            break;
        case 2:
            if (isEmpty(&s))
                printf("\n Stack Underflow");
            else
                printf("\n The element is: %d", pop(&s));
            break;
        case 3:
            if (isEmpty(&s))
                printf("\n Stack Underflow");
            else
                printf("\n The element is: %d", peek(&s));
            break;
        }
    } while (choice != 4);
    return 0;
}