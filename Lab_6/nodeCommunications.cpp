//
//  nodeCommuications.cpp
//  HPC_Labs
//
//  Created by Mohamed Abouelenin on 19/05/2024.
//
#include "mpi.h"
#include "nodeCommunications.hpp"
#include <stdio.h>

void nodeCommunication()
{
    // Initialize MPI
    MPI_Init(NULL, NULL);

    // Get the size
    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Get the rank
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Define variables
    int data = 2, sender, receiver;

    if (rank == 0)
    {
        sender = 3;
        receiver = 1;
        data *= 2;
        MPI_Send(&data, 1, MPI_INT, receiver, 0, MPI_COMM_WORLD);
        printf("Data = %d", data);
        MPI_Recv(&data, 1, MPI_INT, sender, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    if (rank == 1)
    {
        sender = 0;
        receiver = 2;
        MPI_Recv(&data, 1, MPI_INT, sender, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        data *= 2;
        MPI_Send(&data, 1, MPI_INT, receiver, 0, MPI_COMM_WORLD);
        printf("Data = %d", data);
    }
    if (rank == 2)
    {
        sender = 1;
        receiver = 3;
        MPI_Recv(&data, 1, MPI_INT, sender, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        data *= 2;
        MPI_Send(&data, 1, MPI_INT, receiver, 0, MPI_COMM_WORLD);
        printf("Data = %d", data);
    }
    if (rank == 3)
    {
        sender = 2;
        receiver = 0;
        MPI_Recv(&data, 1, MPI_INT, sender, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        data *= 2;
        MPI_Send(&data, 1, MPI_INT, receiver, 0, MPI_COMM_WORLD);
        printf("Data = %d", data);
    }

    // Finish our MPI work
    MPI_Finalize();
}
