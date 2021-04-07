#include<stdio.h>
#include "sstack.h"

int priority(char ch)
{
    switch(ch)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
    case '$':
        return 3;


    }
    return 0;
}

void convert(char infix[20],char post[20])
{
    int i,j=0;
    char ch,ch1;
    stack s;
    init(&s);
    for(i=0;infix[i]!='\0';i++)
    {
      ch=infix[i];
      switch(ch)
      {
      case '(':
        push(&s,ch);
        break;
      case '+':
      case '-':
      case '*':
      case '/':
      case '%':
      case '^':
      case '$':
          while((isempty(&s)!=-1)&&(priority(peek(&s))>=priority(ch)))
            post[j++]=pop(&s);
          push(&s,ch);
          break;
      case ')':
        while((ch1=pop(&s))!='(')
                post[j++]=ch1;
                break;
      default:
        post[j++]=ch;

      }
    }
    while(isempty(&s)!=-1)
        post[j++]=pop(&s);
     post[j]='\0';

}

int main()
{
    char post[20];
    char infix[20]="(a*(b+c)*((d-a)/b))";
    convert(infix,post);
    printf("the postfix string is %s\n",post);
}
