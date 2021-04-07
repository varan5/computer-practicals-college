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
    fptr=fopen("cities.txt","r+");
    if(fptr==NULL)
    {
        printf("error opening the file \n");
        return 0;
    }
    int i=0;
    printf("the details are: \n");

    while(!feof(fptr))
    {
        fscanf(fptr,"%s%d",&citydetails[i].cityname,&citydetails[i].stdcode);
        printf("city name is %s and std code is %d \n",citydetails[i].cityname,citydetails[i].stdcode);
        i++;
    }
    printf("\n enter the name of city to be searched:- ");
    int n=i;
    gets(citydetails[n].cityname);
    printf("\n");
    i=0;
    while(strcmp(citydetails[n].cityname,citydetails[i].cityname)!=0) i++;
    
    if(i==n)
    {
        printf("not found");
    }else{
        printf("found and stdcode is %d \n",citydetails[i].stdcode);
    }
    fclose(fptr);
    return 0;
}

// #include <stdio.h>
// #include<stdlib.h>
// #include<string.h>

// typedef struct city
// {
//     char name[10];
//     int pin; 
// }s;

// void insert(struct city s, int a, FILE *fp)
// {
//     int i;
//    fp=fopen("citiesdemo.txt","a");
//     printf("\n Enter details:\n ");
//     for(i=0; i<a; i++)
//      {
//          fflush(stdin);
//          printf("\n Enter city name and pin : \n");
//          scanf("%s %d" ,s.name,&s.pin);
//          fprintf(fp,"%s %d\n",s.name,s.pin);
//          fflush(stdin);
//      }
    
//      fclose(fp);
// }

// void linearsearch(struct city s, int a, FILE *fp)
// {
//     int i, c,found=0;
//     char ch[10];
//     c = getc(fp);
//     printf("\n Enter city name to find pin code : \n");
//     scanf("%s",&ch);
//     fp=fopen("cities.txt","r");
         
//             while(c != EOF) 
//             {
//              fscanf(fp,"%s%d",s.name,&s.pin);
//              if(strcmp(ch,s.name)==0)
//                {
//                printf("\n City %s pin is %d  .\n",s.name, s.pin);
//                found=1;
//                break;
//                }
//                c=getc(fp);
//             } 
//               if(found==0)
//                  printf("\n City was not found\n");
//     fclose(fp);
// }

// int main()
// {
//     int n;
//     FILE *fp;
//     s se;
//     if(fp=fopen("cities.txt","a+"))
//       {
//         printf("\n File open succesfully.\n");
//         printf("\n Enter how many details; ");
//         scanf("%d",&n);
//         insert(se,n,fp);
//         linearsearch(se,n,fp);
//       }
//     else
//        printf("file doesn't exist.");
//         fclose(fp);
//         return 0;
// }
