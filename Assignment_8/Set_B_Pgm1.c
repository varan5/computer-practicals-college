#include <stdio.h>
#include<math.h>
#include "cstack.h"
#define maxsize 20

int evaluate(char postfix[], int num[])
{
    stack s;
    int value, i, opnd1, opnd2;
    initStack(&s);
    for (i = 0; postfix[i] != '\0'; i++)
    {
        switch (postfix[i])
        {
        case '+':
            opnd2 = pop(&s);
            opnd1 = pop(&s);
            push(&s, opnd1 + opnd2);
            break;

        case '-':
            opnd2 = pop(&s);
            opnd1 = pop(&s);
            push(&s, opnd1 - opnd2);
            break;

        case '*':
            opnd2 = pop(&s);
            opnd1 = pop(&s);
            push(&s, opnd1 * opnd2);
            break;

        case '/':
            opnd2 = pop(&s);
            opnd1 = pop(&s);
            push(&s, opnd1 / opnd2);
            break;

        case '%':
            opnd2 = pop(&s);
            opnd1 = pop(&s);
            push(&s, opnd1 % opnd2);
            break;

        case '^':
        case '$':
            opnd2 = pop(&s);
            opnd1 = pop(&s);
            push(&s, pow(opnd1,opnd2));
            break;

        case 'a':
            push(&s, num[0]);
            break;

        case 'b':
            push(&s, num[1]);
            break;

        case 'c':
            push(&s, num[2]);
            break;

        case 'd':
            push(&s, num[3]);
            break;
        // default:
        //     printf("enter the values of %c",postfix[i]);
        //     scanf("%d",&value);
        //     push(&s,value);
        }
    }
    return pop(&s);
}

int main()
{
    int num[4], i;
    char post[20] = "ab+cd-*ab/";
    int ans;

    printf("enter the values of a b c d\n");
    for (i = 0; i < 4; i++)
    {
        scanf("%d", &num[i]);
    }
    ans = evaluate(post, num);
    printf("the evaluated answer is %d", ans);

}
