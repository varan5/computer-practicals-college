#include <stdlib.h>
#include<stdio.h>
#include<time.h>
void generate(int *,int );
int main()
{
    int array[20],n,i,num,flag=0;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("enter the numbers\n");
    generate(array,n);
    printf("\n elements are\n");
    for(i=0;i<n;i++)
    {
        printf("\n%d",array[i]);
    }
    printf("Enter a number to be searched\n");
    scanf("%d", &num);
    for (i = 0; i < 10; i++)
    {
        if (array[i] == num)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Found at %d\n", i);
    }
    else
    {
        printf("Element not found\n");
    }
    return 0;
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