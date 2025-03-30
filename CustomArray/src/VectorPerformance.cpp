#include "VectorPerformance.h"

VectorPerformance::VectorPerformance() {
    // Constructor implementation (if needed)
}

VectorPerformance::~VectorPerformance() {
    // Destructor implementation (if needed)
}

void VectorPerformance::benchmarkStdVector() {
    /// Record start time
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> vec;

    /// Perform operations
    for (int i = 0; i < 1000000; i++) {
        vec.push_back(i);
    }

    /// Record end time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate duration
    std::chrono::duration<double> duration = end - start;
    std::cout << "std::vector: Initializng & Inserting 1000000 Elements took :- " << duration.count() << " seconds" << std::endl;


    auto start1 = std::chrono::high_resolution_clock::now();
    for(int i = 100 ; i < 120 ; i++)
    {
     vec.erase(vec.begin() + i);
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration1 = end1 - start1;
     std::cout << "std::vector: deleting from index 100 to 120 took :- " << duration.count() << " seconds" << std::endl;

}

/// Extern "C" function definition
extern "C" void benchmarkStdVectorWrapper() {
    VectorPerformance::benchmarkStdVector();
}
