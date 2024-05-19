// OpenMP Labs
// #include "./Lab_1/searchArr.hpp"
// #include "./Lab_2/calcPi.hpp"
// #include "./Lab_3/parallelArraySearch.hpp"
// #include "./Lab_5/cirticalSum.hpp"

#include <stdio.h>

// MPI
#include "mpi.h"

// Lab 6
void nodeCommunication()
{
    // Initialize MPI
    MPI_Init(NULL, NULL);

    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Get Size

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Get Rank

    // Define variables
    int data = 2, sender, receiver;

    // Receive from 3, send to 1
    if (rank == 0)
    {
        sender = 3;
        receiver = 1;
        data *= 2;
        MPI_Send(&data, 1, MPI_INT, receiver, 0, MPI_COMM_WORLD);
        printf("Data = %d\n", data);
        MPI_Recv(&data, 1, MPI_INT, sender, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    // Receive from 0, send to 1
    if (rank == 1)
    {
        sender = 0;
        receiver = 2;
        MPI_Recv(&data, 1, MPI_INT, sender, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        data *= 2;
        MPI_Send(&data, 1, MPI_INT, receiver, 0, MPI_COMM_WORLD);
        printf("Data = %d\n", data);
    }
    // Receive from 1, send to 3
    if (rank == 2)
    {
        sender = 1;
        receiver = 3;
        MPI_Recv(&data, 1, MPI_INT, sender, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        data *= 2;
        MPI_Send(&data, 1, MPI_INT, receiver, 0, MPI_COMM_WORLD);
        printf("Data = %d\n", data);
    }
    // Receive from 2, send to 0
    if (rank == 3)
    {
        sender = 2;
        receiver = 0;
        MPI_Recv(&data, 1, MPI_INT, sender, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        data *= 2;
        MPI_Send(&data, 1, MPI_INT, receiver, 0, MPI_COMM_WORLD);
        printf("Data = %d\n", data);
    }

    // Finish our MPI work
    MPI_Finalize();
}

int main()
{
    nodeCommunication();
    return 0;
}

// MPI Labs
