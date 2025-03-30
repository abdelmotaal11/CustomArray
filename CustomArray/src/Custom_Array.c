#include "Custom_Array.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Initialize the array with a specified initial capacity
 * @param array:- Pointer to the CustomArray
 * @param initial_capacity:-Initial capacity of the array
 */
void initArray(CustomArray *array, size_t initial_capacity) {
    /// Allocate memory for the array with initial_capacity
    array->data = (int *)malloc(initial_capacity * sizeof(int));
    /// Initialize the size of the array to 0
    array->size = 0;
    /// initial capacity of the array
    array->capacity = initial_capacity;
    /// Initialize the mutex lock for thread safety to make sure only one thread access every function
    pthread_mutex_init(&array->lock, NULL);
}

/**
 * @brief inserting elements to the array, expanding capacity as necessary ( Std::Vector logic in C++)
 * @param array :- Pointer to the CustomArray
 * @param element :- The value to be inserted into the array
 */
void insertElement(CustomArray *array, int element) {
    /// Lock the mutex for thread safety
    pthread_mutex_lock(&array->lock);
    /// Check if the array is full
    if (array->size == array->capacity) {
        /// Reallocate memory to the new capacity using a temporary pointer
        ///I used temp in case if the reallocation fails the values of the array will not be lost.
        /// Double the capacity according to the logic of the std::vector
        size_t temp_capacity = array->capacity * 2;
        int *temp = (int *)realloc(array->data, temp_capacity * sizeof(int));
        /// If reallocation fails, print an error and exit the function
        if (temp == NULL) {
            perror("Failed to reallocate memory");
            pthread_mutex_unlock(&array->lock);
            return;
        }
        /// Update the data pointer to the new memory location & the capacity
        array->capacity = temp_capacity;
        array->data = temp;
    }
    /// Insert the new element at the end of the array
    array->data[array->size] = element;
    /// Increment the size by 1
    array->size+=1;
    /// Unlock the mutex after the operation so the next thread inline can use the function now
    pthread_mutex_unlock(&array->lock);
}


/**
 * @brief Remove elements from the array and compact the memory
 * @param array:- Pointer to the CustomArray
 * @param index:- Index of the element to be removed
 */
void deleteElement(CustomArray *array, size_t index) {
    /// Lock the mutex for thread safety
    pthread_mutex_lock(&array->lock);

    /// Check if the index is out of boundaries
    if (index >= array->size) {
        pthread_mutex_unlock(&array->lock);
        return; // Index out of bounds
    }

    /// Shift elements to the left to fill the gap
    ///ex :- if the index is 4 and the size of the array is 7
    /// array[4] will be = array[5] and so on then size of the array will be 6
    for (size_t i = index; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }

    // Decrease the size of the array
    array->size--;

    /// Check if the size is less than or equal to one-fourth of the capacity
    /// It is a common strategy to reduce the capacity at one-fourth helps balance the memory usage and the performance of resizing operations
    /// Because the Vector is based on doubling the size when it is needed
    if (array->size > 0 && array->size <= array->capacity / 4) {
        size_t new_capacity = array->capacity / 2;

        // Reallocate memory to the new capacity using a temporary pointer
        int *temp = (int *)realloc(array->data, new_capacity * sizeof(int));
        if (temp != NULL) {
            array->data = temp;
            array->capacity = new_capacity;
        }
    }

    // Unlock the mutex after the operation
    pthread_mutex_unlock(&array->lock);
}

/**
 * @brief Access elements by index
 * @param array:- Pointer to the CustomArray
 * @param index:- index of the element to be accessed
 * @return The element at the specified index or -1 if the index is out of bounds
 */
int getElement(CustomArray *array, size_t index) {
    /// Lock the mutex for thread safety
    pthread_mutex_lock(&array->lock);
    /// Initialize the return value
    int value;
    /// Check if the index is out of bounds
    if (index >= array->size) {
        value = -1; // Index out of bounds
    } else {
        /// Get the element at the specified index
        value = array->data[index];
    }
    /// Unlock the mutex after the operation
    pthread_mutex_unlock(&array->lock);
    /// Return the accessed element or -1 if out of bounds
    return value;
}

/**
 * @brief Dynamically resize the array to optimize memory usage.
 * @param array Pointer to the CustomArray.
 * @param new_capacity New capacity of the array.
 */
void resizeArray(CustomArray *array, size_t new_capacity) {
    /// Lock the mutex for thread safety
    pthread_mutex_lock(&array->lock);
    /// Reallocate memory to the new capacity using a temporary pointer
    int *temp = (int *)realloc(array->data, new_capacity * sizeof(int));
    /// If reallocation succeeds, update the data pointer and capacity
    if (temp != NULL) {
        array->data = temp;
        array->capacity = new_capacity;
        /// If the new capacity is smaller than the current size, update the size
        if (array->size > new_capacity) {
            array->size = new_capacity;
        }
    } else {
        /// If reallocation fails, print an error message
        perror("Failed to reallocate memory");
    }
    /// Unlock the mutex after the operation
    pthread_mutex_unlock(&array->lock);
}

/**
 * @brief Free the allocated memory.
 * @param array Pointer to the CustomArray.
 */
void freeArray(CustomArray *array) {
    pthread_mutex_lock(&array->lock);
    /// Free the allocated memory
    free(array->data);
    ///to avoid dangling
    array->data = NULL;
    /// Reset the size and capacity
    array->size = 0;
    array->capacity = 0;

    pthread_mutex_unlock(&array->lock);
    /// Destroy the mutex
    pthread_mutex_destroy(&array->lock);
}
