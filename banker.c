#include<stdio.h>
#include<stdlib.h>
int allocation[10][10],need[10][10],max[10][10],available[10],work[10],finish[10],safe[10];
int i,j,p,r,temp=0,s=0,flag=0,ch,ind,req[10];
void check()
{
    temp=0;
    s=0;
    for(i=0;i<p;i++)
    for(j=0;j<r;j++)
    need[i][j]=max[i][j]-allocation[i][j];
    printf("\n need table is::\n");
    for(i=0;i<p;i++)
    {
    for(j=0;j<r;j++)
     printf("%d\t",need[i][j]);
     printf("\n");
    }
   

   for(i=0;i<p;i++)
   finish[i]=0;
   for(i=0;i<r;i++)
   work[i]=available[i];
   while(temp<2)
   {
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            if(finish[j]==0 && need[i][j]<=work[j])
            flag=1;
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            for(j=0;j<r;j++)
            {
                work[j]=work[j]+allocation[i][j];
                finish[i]=1;
                safe[s++]=i;
            }
        }
    }
    temp++;
   }

   flag=0;
   for(i=0;i<p;i++)
   {
    if(finish[i]==0)
    {
        flag=1;
        break;
    }
   }
   if(flag==1)
   {
    printf("system is in deadlock::");
   }
   else{
    printf("system is in safe state::");
    printf("safe seq is:\n");
    for(i=0;i<p;i++)
    printf("P%d\t",safe[i]);
   }
}

int main()
{
    system("clear");
    printf("\n.......................BANKER'S ALGORITHEM..................");
    printf("\n\nenter the no of resources and processes::");
    scanf("%d%d",&r,&p);
    
    printf("enter the allocation table::\n");
    for(i=0;i<p;i++)
    for(j=0;j<r;j++)
    scanf("%d",&allocation[i][j]);
    
    printf("\n enter the max table::\n");
     for(i=0;i<p;i++)
    for(j=0;j<r;j++)
    scanf("%d",&max[i][j]);
    
    printf("\n enter the vector availabel::");
     for(i=0;i<r;i++)
    scanf("%d",&available[i]);
    check();
    
    printf("do you want to add more files[0/1]");
    scanf("%d",&ch);

    if(ch==0)
    exit(1);
    printf("enter process::");
    scanf("%d",&ind);
    printf("enter request::");
    for(i=0;i<r;i++)
    scanf("%d",&req[i]);

    flag=0;
    for(i=0;i<r;i++)
    if(req[i]<=need[ind][i])
     flag=1;
    else
     flag=0;
    if(flag==0)
    {
        printf("request can not be satisfied...");
        exit(1);
    }
    for(i=0;i<r;i++)
    if(req[i]<=available[i])
      flag=1;
    else
     flag=0;
     if(flag==0)
     {
        printf("request cant satisfied....");
        exit(1);
     }

     for(i=0;i<r;i++)
     {
        allocation[ind][i]=allocation[ind][i]+req[i];
        available[i]=available[i]-req[i];
     }
     check();
     return 0;


    
 


}