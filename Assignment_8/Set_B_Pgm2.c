#include<stdio.h>
#include"cstack.h"

int palindrome(char str[])
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
        if(pop(&s)!=str[i])
        return -1;
        else
            i++;
    }
    return 1;

}

int main()
{
    int j;
    char str[20];
    printf("enter a string to check whether palindrome or not:\n");
    scanf("%s",&str);
    j=palindrome(str);
    if(j==1)
        printf("the string %s is a palindrome",str);
    else
        printf("the string %s is not a palindrome",str);
}
