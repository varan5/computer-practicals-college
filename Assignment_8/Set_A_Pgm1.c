#include<stdio.h>
#include"cstack.h"

void reverse(char str[])
{
    int i;
    stack s;
    initStack(&s);
    for(i=0;str[i]!='\0';i++)
    {
        push(&s,str[i]);
    }
    i=0;
    while(isEmpty(&s)!=-1)
    {
        str[i]=pop(&s);
        i++;
    }
}

int main()
{
    char str[20];
    printf("enter the string to be reversed:\n");
    scanf("%s",&str);
    printf("the original string is:\n%s\n",str);
    reverse(str);
    printf("the reversed string is:\n%s\n",str);
}
