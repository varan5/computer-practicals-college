#include<stdio.h>
#include "Set_A_Pgm1.h"
int main()
{
    int i,n,num;
    STACK s,q;
    initStack(&s);
    initStack(&q);
    printf("\n enter the number of elements");
    scanf("%d",&n);
    printf("\n enter the elements in first stack \n");
    for(i=0;i<n;i++)
    {
        printf("enter the %d element:- ",i);
        scanf("%d",&num);
        push(&s,num);
    }
    printf("\n enter the elements in second stack \n");
    for(i=0;i<n;i++)
    {
        printf("enter the %d element:- ",i);
        scanf("%d",&num);
        push(&q,num);
    }
    i=0;
    while(i!=n)
    {
        if(pop(&s)==pop(&q)) 
            i++;
        else 
            break;
    }
    if(i==n)
        printf("\n two stacks are identical");
    else
        printf("\n two stacks are not identical");
    
}