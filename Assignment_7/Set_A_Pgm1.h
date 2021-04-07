#define MAXSIZE 50
typedef struct Stack{
int data[MAXSIZE];
int top;
}STACK;
void initStack(STACK *s){s->top=-1;}
int isEmpty(STACK *s){return s->top==-1;}
int isFull(STACK *s){return s->top==MAXSIZE-1;}
void push(STACK *s,int num){s->data[++s->top]=num;}
int pop(STACK *s){return s->data[s->top--];}
int peek(STACK *s){return s->data[s->top];}