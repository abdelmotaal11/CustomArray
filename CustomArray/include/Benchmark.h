#ifndef BENCHMARK_H
#define BENCHMARK_H

/**
 * @file benchmark.h
 * @brief Header file for benchmarking functions.
 * @details This file contains the function declarations for benchmarking
 *          the performance of a custom dynamic array and comparing it with
 *          the performance of std::vector in C++.
 * @version 1.0
 * @author Mostafa Nasr
 * @date 2024-07-26
 */

/**
 * @brief Benchmark the performance of the CustomArray implementation.
 * @details This function measures the time taken to perform a large number
 *          of insertions & deletion into a CustomArray and prints the duration.
 */
void benchmarkCustomArray();

/**
 * @brief Compare the performance of std::vector and CustomArray.
 * @details This function benchmarks both std::vector and CustomArray by
 *          measuring the time taken to perform a large number of insertions
 *          & deletions prints the durations for comparison.
 */
void benchmarkComparison();

#endif // BENCHMARK_H
