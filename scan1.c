#include<stdio.h>

int main()
{
 int max,head,n,queue[20],queue1[20],queue2[20],temp,temp1=0,temp2=0,seek=0;
 int i,j,diff;
 float avg;
 printf("enter max disk::");
 scanf("%d",&max);
 printf("enter initial head position::");
 scanf("%d",&head);
 printf("enter limit::");
 scanf("%d",&n);
 printf("enter elements::");
 for(i=1;i<=n;i++)
 {
   scanf("%d",&temp);
   if(temp>=head)
   {
    queue1[temp1]=temp;
    temp1++;

   }
   else
   {
    queue2[temp2]=temp;
    temp2++;
   }
 }
for(i=0;i<temp1-1;i++)
{
  for(j=i+1;j<temp1;j++)
  {
    if(queue1[i]>queue1[j])
    {
      temp=queue1[i];
      queue1[i]=queue1[j];
      queue1[j]=temp;
    }
  }
}

for(i=0;i<temp2-1;i++)
{
  for(j=i+1;j<temp2;j++)
  {
    if(queue2[i]<queue2[j])
    {
      temp=queue2[i];
      queue2[i]=queue2[j];
      queue2[j]=temp;
    }
  }
}
for(i=1,j=0;j<temp1;i++,j++)
queue[i]=queue1[j];
queue[i]=max;
for(i=temp1+2,j=0;j<temp2;i++,j++)
queue[i]=queue2[j];
queue[i]=0;
queue[0]=head;
for(j=0;j<=n+1;j++)
{
  diff=abs(queue[j+1]-queue[j]);
  seek+=diff;
  printf("move from %d to %d with seek %d",queue[j],queue[j+1],diff);
}
printf("total seek time=%d",seek);
avg=seek/(float)n;
printf("avegrafe=%f",avg);
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
/*  printf("enter max range of disk::");
 scanf("%d",&max);
 printf("enter initial head position::");
 scanf("%d",&head);
 printf("enter limit of elements of queue request:");
 scanf("%d",&n);
 printf("enter the elements::\n");
for(i=1;i<=n;i++)
{
    scanf("%d",&temp);
    if(temp>=head)
    {
        queue1[temp1]=temp;
        temp1++;
    }
    else
    {
        queue2[temp2]=temp;
        temp2++;
    }
}
    for(i=0;i<temp1-1;i++)
    {
        for(j=i+1;j<temp1;j++)
        {
            if(queue1[i]>queue1[j])
            {
                temp=queue1[i];
                queue1[i]=queue1[j];
                queue[j]=temp;
            }
        }
    }
    for(i=0;i<temp2-1;i++)
    {
      for(j=i+1;j<temp2;j++)
      {
        if(queue2[i]<queue2[j])
        {
          temp=queue2[i];
          queue2[i]=queue2[j];
          queue2[j]=temp;
        }
      }
    } 
    for(i=1,j=0;j<temp1;i++,j++)
      queue[i]=queue1[j];
      queue[i]=max;
      for(i=temp1+2,j=0;j<temp2;i++,j++)
      queue[i]=queue2[j];
      queue[i]=0;
      queue[0]=head;
     
      for(j=0;j<=n+1;j++)
      {
        diff=abs(queue[j+1]-queue[j]);
        seek+=diff;
        printf("disk head move from %d to %d with seek %d\n",queue[j],queue[j+1],diff);
      }
      printf("total seek time is = %d\n",seek);
      avg=seek/(float)n;
      printf("average seek time is %f\n",avg);
      return 0;
      
}*/
