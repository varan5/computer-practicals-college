#define MAXSIZE 100
#include<stdio.h>
typedef struct 
{
    int data[MAXSIZE];
    int right,left;
}QUEUE;

void init(QUEUE *pq)
{
    pq->right=pq->left=MAXSIZE-1;
}

int isFull(QUEUE *pq)
{
    return (((pq->right+1)%MAXSIZE)==pq->left);
}

int isEmpty(QUEUE *pq)
{
    return pq->right==pq->left;
}

void insertRight(QUEUE *pq,int num)
{
    if(isFull(pq))
    {
        printf("OVERFLOW");
    }else{
        pq->right=(pq->right+1)%MAXSIZE;
        pq->data[pq->right]=num;
    }
}

void insertLeft(QUEUE *pq,int num)
{
    if(isFull(pq))
    {
        printf("OVERFLOW");
    }else{
        pq->data[pq->left]=num;
        if(pq->left==0)
            pq->left=MAXSIZE-1;
        else
            pq->left--;
    }
}

int removeLeft(QUEUE *pq)
{
    pq->left=(pq->left+1)%MAXSIZE;
    return pq->data[pq->left];
}

int removeRight(QUEUE *pq)
{
    int num=pq->data[pq->right];
    if(pq->right==0)
        pq->right=MAXSIZE-1;
    else
        pq->right--;
    return num;
}

