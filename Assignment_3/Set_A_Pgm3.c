#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void generate(int *, int);
void quickSort(int *, int ,int);
int partition(int *,int,int);
int main()
{
    int array[20], n, i, num, flag = 0;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    generate(array, n);
    printf("unsorted elements are\n");
    for (i = 0; i < n; i++)
    {
        printf("\n%d", array[i]);
    }
    quickSort(array, 0,n-1);
    printf("Sorted elements are:-\n");
    for (i = 0; i < n; i++)
    {
        printf("\n%d", array[i]);
    }
    return 0;
}
void generate(int *a, int n)
{
    int i;
    srand(time(0));
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
}
void quickSort(int *a,int lb,int ub)
{
    int j;
    if(lb<ub)
    {
        j=partition(a,lb,ub);
        quickSort(a,lb,j-1);
        quickSort(a,j+1,ub);
    }
}
int partition(int *a,int lb,int ub)
{
    int up,dn,temp,pivot;
    up=ub;
    dn=lb+1;
    pivot=a[lb];
    do{
        while((a[dn]<pivot)&& (dn<=ub))
            dn++;
        while((a[up]>pivot)&&(up>lb))
            up--;
        if(dn<up)
        {
            temp=a[dn];
            a[dn]=a[up];
            a[up]=temp;
        }
    }while(dn<up);
    a[lb]=a[up];
    a[up]=pivot;
    return up;
}