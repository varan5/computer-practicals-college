#include<stdio.h>
int search(int a[],int n,int key);
int main()
{
    int array[20],n,i,num,pos;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("enter the numbers\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("Enter a number to be searched\n");
    scanf("%d", &num);
    pos=search(array,n,num);
    if(pos==-1)
    {
        printf("element not found\n");
    }else{
    printf("element found at position %d",pos);
    }
    return 0;
}

int search(int a[],int n,int key)
{
    int begin=0,mid;
    int end=n-1;
    while(begin<=end)
    {
        mid=(end+begin)/2;
        if(a[mid]==key)
        {
            return mid;
        }else{
            if(key<a[mid])end=mid-1;
            else begin=mid+1;
        }
    }
    if(begin>end)
        return -1;
}