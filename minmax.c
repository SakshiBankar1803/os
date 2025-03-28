#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#define N 1000
#define SEED 12345
int main(int argc,char *argv)
{
    int rank,size,i;
    int local_min,local_max,global_min,global_max;
    int number[N],int local_number[N];
    MPI_Init(&argc,&argv);

    MPI_Comm_rank(MPI_COMM_WOLRD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    if(rank==0)
    {
        srand(SEED);
        for(i=1;i<N;i++)
        {
            number[i]=rand()%1000;
        }
    }
    MPI_Scatter(number,N/size,MPI_INT,local_number,N/size,MPI_INT,0,MPI_COMM_WOLRD);
    local_min=local_number[0];
    local_max=local_number[0];
    for(i=1;i<N/size;i++)
    {
        if(local_number[i]<local_min)
        {
            local_min=local_number[i];
        }
        if(local_number[i]>local_max)
        {
            local_max=local_number[i];
        }
    }
    MPI_Reduce(&local_min,&global_min,1,MPI_INT,MPI_MIN,0,MPI_COMM_WOLRD);
    MPI_Reduce(&local_max,&global_max,1,MPI_INT,MIN_MAX,0,MPI_COMM_WOLRD);
    if(rank==0)
    {
       printf("\n global min value=%d\n",global_min);
       printf("\n global max value=%d\n",global_max);
    }
    MPI_Finalize();
    return 0;
}