#ifndef CUSTOM_ARRAY_H
#define CUSTOM_ARRAY_H

#include <stddef.h>
#include <pthread.h>

/**
 * @file custom_array.h
 * @brief Header file for CustomArray implementation.
 * @details This file contains the structure definition and function declarations for a custom dynamic array.
 * @version 1.0
 * @date 2024-07-24
 * @author Mostafa Nasr
 * @note The functions ensure efficient memory management and thread safety.
 */

// Define the structure for CustomArray
typedef struct {
    int *data;             ///< Pointer to the array data
    size_t size;           ///< Current size of the array
    size_t capacity;       ///< Current capacity of the array
    pthread_mutex_t lock;  ///< Mutex lock for thread safety
} CustomArray;

/**
 * @brief Initialize the array with a specified initial capacity.
 * @param array Pointer to the CustomArray.
 * @param initial_capacity Initial capacity of the array.
 */
void initArray(CustomArray *array, size_t initial_capacity);

/**
 * @brief Add elements to the array, expanding capacity as necessary.
 * @param array Pointer to the CustomArray.
 * @param element Element to be inserted into the array.
 */
void insertElement(CustomArray *array, int element);

/**
 * @brief Remove elements from the array and compact the memory.
 * @param array Pointer to the CustomArray.
 * @param index Index of the element to be removed.
 */
void deleteElement(CustomArray *array, size_t index);

/**
 * @brief Access elements by index.
 * @param array Pointer to the CustomArray.
 * @param index Index of the element to be accessed.
 * @return The element at the specified index, or -1 if the index is out of bounds.
 */
int getElement(CustomArray *array, size_t index);

/**
 * @brief Dynamically resize the array to optimize memory usage.
 * @param array Pointer to the CustomArray.
 * @param new_capacity New capacity of the array.
 */
void resizeArray(CustomArray *array, size_t new_capacity);

/**
 * @brief Free the allocated memory.
 * @param array Pointer to the CustomArray.
 */
void freeArray(CustomArray *array);

#endif // CUSTOM_ARRAY_H
