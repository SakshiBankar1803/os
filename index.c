#include<stdio.h>
#include<stdlib.h>
int main()
{
    int f[50],i,j,k,c,p,a,st,len;
    for(i=0;i<50;i++)
    f[i]=0;
    printf("enter how many block already allocated:: ");
    scanf("%d",&p);
    printf("enter allocated blocks::");
    for(i=0;i<p;i++)
    {
        scanf("%d",&a);
        f[a]=1;
    }
   x: printf("enter starting block and length::");
    scanf("%d%d",&st,&len);
    k=len;
    if(f[st]==0)
    {
        for(j=st;j<(st+k);j++)
        {
            if(f[j]==0)
            {
                f[j]=1;
                printf("\n%d----->%d",j,f[j]);
            }
            else
            {
                printf("%d  block is allocated",j);
                k++;
            }
        }
    }
    else
    { 
        printf("%d starting block is already aloocated",st);
        printf("do you want to add more block[0/1]");
        scanf("%d",&c);
        if(c==1)
        goto x;
        else
        exit(0);

    }
}

/* OUTPUT
bcs@bcs-OptiPlex-3050:~$ ./a.out
enter how many blocks already allocated::5 
enter blocks already allocated::13 15 17 18 20
enter index starting block and length::15 5
15 starting block is already allocated 
do you want to enter more file(yes - 1/no - 0)1
enter index starting block and length::17 3
17 starting block is already allocated 
do you want to enter more file(yes - 1/no - 0)1   
enter index starting block and length::5 
10
5---------->1
6---------->1
7---------->1
8---------->1
9---------->1
10---------->1
11---------->1
12---------->1
13 block is already allocated
14---------->1
15 block is already allocated
16---------->1
bcs@bcs-OptiPlex-3050:~$ 
*/


/*#include<stdio.h>
#include<stdlib.h>
int main()
{
    int p,st,len,k,i,f[50],a,j,c;
    for(i=0;i<50;i++)
    f[i]=0;
   printf("enter how many block already allocated..::");
    scanf("%d",&p);
    printf("enter block that already allocated..");
    for(i=0;i<p;i++)
    {
        scanf("%d",&a);
        f[a]=1;
    }
   x: printf("enter starting block and length::");
    scanf("%d%d",&st,len);
    k=len;
    if(f[st]==0)
    {
        for(j=st;j<(st+k);j++)
          {
            if(f[j]==0)
            {
                f[j]=1;
                printf("block %d->%d",j,f[j]);
            }
            else
            {
                printf("%d block is already allocated",j);
                k++;
            }
          }
    }
    else
    {
        printf(" %d stating block is already allocated",st);
        printf("do you want to add more files[0/1]");
        scanf("%d",&c);
        if(c==1)
        goto x;
        else
        exit(0);
    }

}*/