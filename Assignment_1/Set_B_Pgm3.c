#include<stdio.h>
#include<string.h>
typedef struct{
    char cityname[30];
    int stdcode;
}city;
int main()
{
    city citydetails[100];
    char cityname[30];
    FILE *fptr;
    fptr=fopen("sortedcitiex.txt","r");
    if(fptr==NULL)
    {
        printf("error opening the file \n");
        return 0;
    }
    int i=0;
    printf("the details are: \n");

    while(!feof(fptr))
    {
        fscanf(fptr,"%s%d",citydetails[i].cityname,&citydetails[i].stdcode);
        printf("city name is %s and std code is %d \n",citydetails[i].cityname,citydetails[i].stdcode);
        i++;
    }
    printf("\n enter the name of city to be searched:- ");
    gets(cityname);
    printf("\n");
    int n=i,flag=0;
    int low=0,mid;
    int high=n-1;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(strcmp(citydetails[mid].cityname,cityname)==0)
        {
            printf("found %s",citydetails[mid].cityname);
            return 0;
        }else{
            if(strcmp(citydetails[mid].cityname,cityname)==1)high=mid-1;
            else low=mid+1;
        }
    }
    printf("not found");
    fclose(fptr);
    return 0;
}
