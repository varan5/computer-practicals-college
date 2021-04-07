#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void generate(int *,int );
int search(int a[],int n,int key);
int main()
{
    int array[20],n,i,num,pos;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    generate(array,n);
    printf("\n elements are\n");
    for(i=0;i<n;i++)
    {
        printf("\n%d",array[i]);
    }
    printf("Enter a number to be searched\n");
    scanf("%d", &num);
    pos=search(array,10,num);
    if(pos==-1)
    {
        printf("element not found\n");
    }else{
        printf("%d found at %d\n",num,pos);
    }
    return 0;
}

int search(int a[],int n,int key)
{
    int i=0;
    a[n]=key;
    while(a[i]!=key) i++;
    if(i==n)
        return -1;
    else
        return i;
    
}
void generate(int *a,int n)
{
    int i;
    srand(time(0));
    for(i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }
}