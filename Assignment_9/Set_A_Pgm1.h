#define MAXSIZE 100
typedef struct
{
    int data[MAXSIZE];
    int front, rear;
} QUEUE;

void initQueue(QUEUE *pq) { pq->front = pq->rear = -1; }
void addq(QUEUE *pq, int num)
{
    pq->rear++;
    pq->data[pq->rear] = num;
}
int removeq(QUEUE *pq)
{
    int num;
    pq->front++;
    num = pq->data[pq->front];
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