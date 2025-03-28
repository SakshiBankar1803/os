#include<stdio.h>
int main()
{
 int i,temp[10],a[10],sum=0,n,disk;
 printf("enter head position::");
 scanf("%d",&disk);
 printf("enter limit of quwue::");
 scanf("%d",&n);
 printf("enter the elements of quwuew::");
 for(i=0;i<n;i++)
 {
    scanf("%d",&a[i]);
    temp[i]=disk-a[i];
    if(temp[i]<0)
    {
        temp[i]=a[i]-disk;

    }
    disk=a[i];
    sum=sum+temp[i];
 }
 printf("\n total head movement of cylinder=%d",sum);
}


/*int main()
{
 int i,j,sum=0,n;
 int ar[20],tm[20];
 int disk;
 printf("enter nos of location\t");
 scanf("%d",&n);
 printf("enter position of head\t");
 scanf("%d",&disk);
 printf("enter elements of disk queue\n");
 for(i=0;i<n;i++)
 {
   scanf("%d",&ar[i]);
   tm[i]=disk-ar[i];
   if(tm[i]<0)
   {
     tm[i]=ar[i]-disk;
   }
   disk=ar[i];
   sum=sum+tm[i];
   }
   printf("\n movement of total cylinders %d",sum);
 
}*/