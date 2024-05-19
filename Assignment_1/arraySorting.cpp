//
//  arraySorting.cpp
//  HPC_Labs
//
//  Created by Mohamed Abouelenin on 19/05/2024.
//

#include "arraySorting.hpp"

#include <iostream>
#include <stdio.h>
#include <omp.h>
using namespace std;
#define N 10000

void sortArray()
{
    int arr[N];
    int temp = 0; // Holds the value before switching

    for (int i = 0; i < N; i++)
        arr[i] = rand() % 10000; // Generate random value

    // Find space of the minimum number
    for (int i = 0; i < N - 1; i++)
        
    // Compare and sort the array
#pragma omp for
        for (int j = i + 1; j < N; j++)
            if (arr[j] <= arr[i])
            {
                temp = arr[i];
                // Swap the maximum value with the minimum value
                arr[i] = arr[j];
                arr[j] = temp;
            }

    for (int i = 0; i < N; i += 3){
        cout << arr[i];
        if (i + 1 < N)
            cout <<", "<< arr[i + 1];
        if (i + 2 < N)
            cout <<", "<< arr[i + 2];
        cout << endl;
    }
}
