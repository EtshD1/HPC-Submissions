
#include <stdio.h>
#include "mpi.h"

int main()
{
    MPI_Init(NULL, NULL);
    int size, id;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);

    if (id == 0)
    {
        int Data[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        MPI_Send(&Data[5], 5, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(&Data[10], 5, MPI_INT, 2, 0, MPI_COMM_WORLD);
        int localsum = 0;
        for (int i = 0; i < 5; i++)
            localsum += Data[i];

        MPI_Status X_Status;
        int sum1, sum2;
        MPI_Recv(&sum1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &X_Status);
        MPI_Recv(&sum2, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, &X_Status);
        printf("Process of ID: %d\n", id);
        printf("Total sum of array: %d\n\n", localsum + sum1 + sum2);
    }
    else if (id <= 2)
    {
        int Data[5];
        MPI_Status X_Status;
        MPI_Recv(&Data, 5, MPI_INT, 0, 0, MPI_COMM_WORLD, &X_Status);
        int localsum = 0;
        for (int i = 0; i < 5; i++)
            localsum += Data[i];

        MPI_Send(&localsum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        printf("Process of ID: %d\n", id);
        printf("Total sum of array: %d\n\n", localsum);
    }

    MPI_Finalize();
    return 0;
}
