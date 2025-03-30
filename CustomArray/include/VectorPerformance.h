#ifndef VECTORPERFORMANCE_H
#define VECTORPERFORMANCE_H

#include <vector>
#include <chrono>
#include <iostream>

/**
 * @file VectorPerformance.h
 * @brief Header file for benchmarking std::vector performance.
 * @details This file contains the class definition and function declarations
 *          for benchmarking the performance of std::vector in C++.
 * @version 1.0
 * @author Mostafa Nasr
 * @date 2024-07-24
 */

/**
 * @class VectorPerformance
 * @brief Class for benchmarking std::vector performance.
 * @details This class provides functionality to benchmark the performance of
 *          std::vector by measuring the time taken to perform a large number
 *          of insertions.
 */
class VectorPerformance
{
public:
    /**
     * @brief Constructor for VectorPerformance.
     */
    VectorPerformance();

    /**
     * @brief Destructor for VectorPerformance.
     */
    virtual ~VectorPerformance();

    /**
     * @brief Benchmark the performance of std::vector.
     * @details This static function measures the time taken to perform a large
     *          number of insertions into a std::vector and prints the duration.
     */
    static void benchmarkStdVector(); // Declare as static

protected:

private:
};

/**
 * @brief Extern "C" function declaration for benchmarking std::vector.
 * @details This function allows the C++ function benchmarkStdVector to be
 *          called from C code.
 */
extern "C" void benchmarkStdVectorWrapper();

#endif // VECTORPERFORMANCE_H
