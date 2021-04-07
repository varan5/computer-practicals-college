
typedef struct stack
{
    int a[30];
    int top;
}stack;


void initStack(stack *ps)
{
    ps->top=-1;
}

void push(stack *ps,int num)
{
    ps->top++;
    ps->a[ps->top]=num;
}

int pop(stack *ps)
{
    int num;
    num=ps->a[ps->top];
    ps->top--;
    return num;
}

int isEmpty(stack *ps)
{
    if(ps->top==-1)
        return -1;
        else
            return 1;

}

char peek(stack *ps)
{
    char num;
    num=ps->a[ps->top];
    return num;
}

int isFull(stack *ps)
{
    if(ps->top==20)
        return -1;
        else
            return 1;
}

