#include "Set_A_Pgm2.h"
int main()
{
    int choice, data;
    initStack();
    do
    {
        printf("\n1:PUSH\n2:POP\n3:PEEK\n4:EXIT");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
                printf("\n Enter the element: ");
                scanf("%d", &data);
                push(data);
            break;
        case 2:
            if (isEmpty(top))
                printf("\n Stack Underflow");
            else
                printf("\n The element is: %d", pop(top));
            break;
        case 3:
            if (isEmpty(top))
                printf("\n Stack Underflow");
            else
                printf("\n The element is: %d", peek(top));
            break;
        }
    } while (choice != 4);
    return 0;
}