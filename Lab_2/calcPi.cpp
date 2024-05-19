//
//  main.cpp
//  Lab_1_HPC
//
//  Created by Mohamed Abouelenin on 24/02/2024.
//
#include <stdio.h>
#include <omp.h>
#include <cmath>
#include <iostream>

void calculatePi() {
    int nPoints = 10000000; // Number of points
    int tid, nthreads = 8; // tid represents the thread number, nthreads are the number of threads to be made
    int nInside = 0; // Number of points inside a circle
    double rand_x, rand_y; // randomly generated points between 0-1
    
    #pragma omp parallel private(tid) reduction(+: nInside) num_threads(nthreads)
    {
        tid = omp_get_thread_num();
        
        int start = tid * (nPoints / nthreads);
        int end = (tid + 1) * (nPoints / nthreads);
        
        for (int i = start; i < end; i++) {
            rand_x = (double)(rand() % 100)/ 100.00;
            rand_y = (double)(rand() % 100)/ 100.00;
            
            if (pow(rand_x, 2) +  pow(rand_y, 2) <= 1)
                nInside++;
        }
    }
    
    std::cout << nInside << std::endl;
    
    double my_pi = (double)4 * ((double)nInside/nPoints);
    
    std::cout << my_pi << ':' << M_PI << std::endl;
    std::cout << (M_PI/my_pi) * 100 << std::endl;
}
