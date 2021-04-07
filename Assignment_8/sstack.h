
typedef struct stack
{
    int a[30];
    int top;
}stack;


void init(stack *ps)
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

int isempty(stack *ps)
{
    if(ps->top==-1)
        return -1;
        else
            return 1;

}

char peek(stack *ps)
{
    int num;
    num=ps->a[ps->top];
    return num;
}

int isfull(stack *ps)
{
    if(ps->top==30)
        return -1;
        else
            return 1;
}

