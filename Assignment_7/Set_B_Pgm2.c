#include<stdio.h>
#include "Set_A_Pgm1.h"
int main()
{
    int i,n,num;
    STACK s,q,tmp;
    initStack(&s);
    initStack(&q);
    initStack(&tmp);
    printf("\n enter the number of elements");
    scanf("%d",&n);
    printf("\n enter the elements in first stack \n");
    for(i=0;i<n;i++)
    {
        printf("enter the %d element:- ",i);
        scanf("%d",&num);
        push(&s,num);
    }
    for(i=0;i<n;i++)
    {
        num=pop(&s);
        push(&tmp,num);
        push(&q,num);
    }
    // for(i=0;i<n;i++)
    // {
    //     num=pop(&tmp);
    //     push(&q,num);
    // }
    printf("\n elements in q stack are \n");
    for(i=0;i<n;i++)
    {
        num=pop(&q);
        printf("%d\n",num);
    }
    return 0;    
}