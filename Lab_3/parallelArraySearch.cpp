//
//  parallelArraySearch.cpp
//  HPC_Labs
//
//  Created by Mohamed Abouelenin on 02/03/2024.
//

#include "parallelArraySearch.hpp"

using namespace std;

#define N 10000

void parallelArraySearch(){
    int a[N];
    
    int count = 0;
    
    for (int i = 0; i < N; i++)
        a[i] = rand() % 50;
        
    clock_t start_time = clock(); // Start Timer
    
#pragma omp parallel for schedule(dynamic, 5) // Dynamic Scheduling
    for (int i = 0; i < N; i++)
            if (a[i] < 25)
                count++;
    
    clock_t end_time = clock(); // End Timer
    
    double execution_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    
    cout << "Items less than 25: " << count << endl;
    
    cout << "Execution time: " << execution_time << " seconds" << endl;
}
