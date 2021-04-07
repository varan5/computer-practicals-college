#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void generate(int *, int,int);
void countSort(int *, int ,int);
int main()
{
    int array[20], n, i,k, num, flag = 0;
    printf("Enter the number of elements and value of k\n");
    scanf("%d %d", &n,&k);
    generate(array,k, n);
    printf("unsorted elements are\n");
    for (i = 0; i < n; i++)
    {
        printf("\n%d", array[i]);
    }
    countSort(array, k,n);
    printf("Sorted elements are:-\n");
    for (i = 0; i < n; i++)
    {
        printf("\n%d", array[i]);
    }
    return 0;
}
void generate(int *a, int k,int n)
{
    int i;
    srand(time(0));
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % k;
    }
}
void countSort(int *a,int k,int n)
{
    int i,c[20]={0},b[20];
    for(i=0;i<n;i++)
        c[a[i]]+=1;
    for(i=1;i<=k;i++)
        c[i]=c[i]+c[i-1];
    for(i=n-1;i>=0;i--)
    {
        b[c[a[i]]-1]=a[i];
        c[a[i]]-=1;
    }
    for(i=0;i<n;i++)
        a[i]=b[i];

}