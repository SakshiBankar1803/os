#include<stdio.h>
int main()
{
    int diff,seek=0,temp1=0,temp2=0,temp,queue[20],queue1[20],queue2[20],i,j,max,head,n;
    float avg;
   
    printf("enter max disk size::");
    scanf("%d",&max);
    printf("enter initial head position::");
    scanf("%d",&head);
    printf("enter limit::");
    scanf("%d",&n);
    printf("enter elemets::");
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
            if(queue2[i]>queue2[j])
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
    queue[i+1]=0;
    for(i=temp1+3,j=0;j<temp2;i++,j++)
    queue[i]=queue2[j];
    //queue[i]=0;
    queue[0]=head;
    for(j=1;j<=n+1;j++)
    {
        diff=abs(queue[j+1]-queue[j]);
        seek+=diff;
       
        printf("move from %d to %d with seek time %d",queue[j],queue[j+1],diff);
    }
    printf("total seek time=%d",seek);
    avg=seek/(float)n;
    printf("avg=%f",avg);

}