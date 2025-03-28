#include<stdio.h>
#include<stdlib.h>
int main()
{
  int f[50],i,j,k,len,st,p,a,flag,c;
  for(i=0;i<50;i++)
  f[i]=0;
  printf("enter how many blocks already allocated:");
  scanf("%d",&p);
  printf("enter allocated blocks::");
  for(i=0;i<p;i++)
  {
    scanf("%d",&a);
    f[a]=1;
  }  
 x: printf("enter starting block and length::");
  scanf("%d%d",&st,&len);
  flag=0;
  for(k=st;k<(st+len);k++)
  {
    if(f[k]==0)
    {
        flag++;
    }
  }
  if(len==flag)
  {
    for(j=st;j<(st+len);j++)
    {
        if(f[j]==0)
        {
            f[j]=1;
            printf("\n%d--->%d",j,f[j]);
        }
        
    }
  }
  else
  {
    printf("block is already allocated");
    goto x;
  }
  printf("do you want to add more blocks[0/1]");
  scanf("%d",&c);
  if(c==1)
  goto x;
  else 
  exit(0);
}