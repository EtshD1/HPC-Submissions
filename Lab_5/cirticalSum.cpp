//
//  CirticalSum.cpp
//  HPC_Labs
//
//  Created by Mohamed Abouelenin on 19/05/2024.
//
#include <ctime>
#include <stdio.h>
#include <iostream>
#include <omp.h>

#define size 100

void criticalSum()
{
	srand(time_t(0)); // Using this method ensures that the numbers are random and not patterned

	// Initialize arrays
	int a1[size] = {0};
	int a2[size] = {0};
	int a3[size] = {0};
    
	int sum = 0;
    
    clock_t start_time = clock(); // Start Timer

	// Filling a1 and a2 using parallelization
#pragma omp parallel for
	for (int i = 0; i < size; i++)
	{
		a1[i] = rand() % 100;
		a2[i] = rand() % 100;
	}

	// Multiply a1 and a2 into array3
#pragma omp parallel for
	for (int i = 0; i < size; i++)
		a3[i] = a1[i] * a2[i];

	
    // Summation. Share variables are sum and a3
#pragma omp parallel for shared(a3, sum)
	for (int i = 0; i < size; i++)
#pragma omp critical // Ensure that the following is executed by one thread at a time
		sum += a3[i]; // sum of array 3 element
    
    
    clock_t end_time = clock(); // End Timer
    
    double execution_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC; // Time in seconds
    
    std::cout << "Sum: " << sum << std::endl;
    
    std::cout << "Execution Time: " << execution_time << std::endl;
}
