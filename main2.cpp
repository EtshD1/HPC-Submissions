#include <stdio.h>
#include <iostream>
#include "mpi.h"

#define vLength 3

int main()
{
	int size, rank;
	int v[vLength];
	int m[vLength][vLength];
	int mT[vLength][vLength];
	int subMT[vLength];
	int localSum = 0;
	int fResult[vLength];
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0)
	{
		srand(size);
		printf("Vector: ");
		for (int i = 0; i < vLength; i++)
		{
			v[i] = rand();
			printf("%d ", v[i]);
		}
		printf("\n\nMatrix:\n");
		for (int i = 0; i < vLength; i++)
		{
			for (int j = 0; j < vLength; j++)
			{
				m[i][j] = rand();
				printf("%d ", v[i]);
			}
			printf("\n");
		}

		printf("\n\nTranspose:\n");
		for (int i = 0; i < vLength; i++)
		{
			for (int j = 0; j < vLength; j++)
			{
				mT[i][j] = m[j][i];
				printf("%d ", mT[i][j]);
				if (j == vLength - 1)
					printf("\n");
			}
		}
	}

	MPI_Bcast(&v, vLength, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(&mT, (vLength * vLength / size), MPI_INT, &subMT, (vLength * vLength / size), MPI_INT, 0, MPI_COMM_WORLD);
	for (int i = 0; i < vLength; i++)
		localSum = v[i] * subMT[i];
	MPI_Gather(&localSum, (vLength / size), MPI_INT, &fResult, (vLength / size), MPI_INT, 0, MPI_COMM_WORLD);

	MPI_Finalize();
	if (rank == 0)
	{
		printf("\n\nResult:\n");
		for (int i = 0; i < vLength; i++)
			printf("%d ", fResult[i]);
	}
	printf("\n");
	return 0;
}