//
//  main.cpp
//  Lab_1_HPC
//
//  Created by Mohamed Abouelenin on 23/02/2024.
//
#include <iostream>
#include <omp.h>

#define N 80
#define MOD 20

void searchArray() {
    int arr[N];
    // srand(time(0)); // Using this method ensures that the numbers are random and not patterned
    
    // Fill the array with random numbers
    for (int i = 0; i < N; i++)
        arr[i] = rand() % MOD;
    
    int nthreads = 4; // Number of threads
    
    std::cout << "Findings:" << std::endl;
    // Begin parallel computing with nthreads (4)
    #pragma omp parallel num_threads(nthreads)
    {
        int tid = omp_get_thread_num(); // Get thread id
        
        // Loop over arr values with selected indexes based on the thread
        for (int i = tid * (N / nthreads); i < (tid + 1) * (N / nthreads); i++) {
            int element = arr[i]; // element of the current loop
            
            // Print the index and the thread of the loop if the element is 15
            if (element == 15)
                printf("Found 15 at index:%d, thread number: %d\n", i, omp_get_thread_num());
            
        }
    }
    
    // std::cout << std::endl << "Array Values:" << std::endl;
    // Print the array values to confirm findings
    // for (int i = 0; i < N; i++)
        // std::cout << i << ":" << arr[i] << std::endl;
}
