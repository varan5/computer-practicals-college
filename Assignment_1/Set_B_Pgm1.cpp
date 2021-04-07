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
    fptr=fopen("cities.txt","r");
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
    for(i=0;i<n;i++)
    {
        if(strcmp(cityname,citydetails[i].cityname)==0)
        {
            flag=citydetails[i].stdcode;
            break;
        }
    }
    if(!flag==0)
    {
        printf("found and stdcode is %d\n",flag);
    }else{
    printf("not found\n");
    }
    fclose(fptr);
    return 0;
}
