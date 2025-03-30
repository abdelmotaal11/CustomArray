#include "benchmark.h"
#include <stdio.h>
#include "Custom_Array.h"


void benchmarkCustomArray() {
    CustomArray array;
    initArray(&array, 10);

    clock_t start = clock();
    for (int i = 0; i < 1000000; i++) {
        insertElement(&array, i);
    }
    clock_t end = clock();
    printf("CustomArray: Inserting 1000000 took :-  %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    clock_t start1 = clock();
    for(int i = 0 ; i < 120 ; i++)
    {
     deleteElement(&array , i);
    }

    clock_t end1 = clock();
    printf("CustomArray: deleting from index 100 to 120 took :-  %f seconds\n", (double)(end1 - start1) / CLOCKS_PER_SEC);


    freeArray(&array);
}

void benchmarkComparison() {
    /// Call the C++ vector benchmark function
    extern void benchmarkStdVectorWrapper();
    benchmarkStdVectorWrapper();
    benchmarkCustomArray();
}
