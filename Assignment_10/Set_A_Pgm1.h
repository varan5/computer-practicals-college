#define MAXSIZE 100
typedef struct 
{
    int data[MAXSIZE];
    int front,rear;
}QUEUE;

void init(QUEUE *pq)
{
    pq->front=pq->rear=-1;
}

void addq(QUEUE *pq,int num)
{
    int i;
    for(i=pq->rear;i>pq->front;i--)
    {
        if(num>pq->data[i])
            pq->data[i+1]=pq->data[i];
        else
            break;
    }
    pq->data[i+1]=num;
    pq->rear++;
}

int removeq(QUEUE *pq)
{
    int num;
    pq->front++;
    num=pq->data[pq->front];
    return num;
}
int peek(QUEUE *pq)
{
    return pq->data[pq->front+1];
}
int isEmpty(QUEUE *pq)
{
    return pq->front==pq->rear;
}
int isFull(QUEUE *pq)
{
    return pq->rear==MAXSIZE-1;
}