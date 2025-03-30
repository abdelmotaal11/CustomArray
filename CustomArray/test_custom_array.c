#include <assert.h>
#include <stdio.h>
#include "Custom_Array.h"

/**
 * @file test_custom_array.c
 * @brief Test suite for CustomArray implementation.
 * @details This file contains functions to test the initialization, insertion, deletion,
 *          element access, and resizing functionalities of the CustomArray.
 * @version 1.0
 * @date 2024-07-24
 * @author Mostafa Nasr
 */

/**
 * @brief Test the initialization of the CustomArray.
 * @details This function initializes a CustomArray with a specified initial capacity
 *          and asserts that the size, capacity, and data pointer are correctly set.
 */
void testInitArray() {
    CustomArray array;
    initArray(&array, 10);

    assert(array.size == 0);
    assert(array.capacity == 10);
    assert(array.data != NULL);

    freeArray(&array);
    printf("testInitArray passed\n");
}

/**
 * @brief Test the insertion of elements into the CustomArray.
 * @details This function inserts elements into a CustomArray, checking that the size
 *          and capacity are correctly updated, and that the array resizes as needed.
 */
void testInsertElement() {
    CustomArray array;
    initArray(&array, 2);

    insertElement(&array, 1);
    insertElement(&array, 2);

    assert(array.size == 2);  // Ensure the size is updated correctly
    assert(array.capacity == 2);  // Ensure the capacity remains unchanged

    insertElement(&array, 3);

    assert(array.size == 3);  // Ensure the size is updated correctly
    assert(array.capacity == 4);  // Ensure the capacity is doubled

    freeArray(&array);
    printf("testInsertElement passed\n");
}

/**
 * @brief Test the deletion of elements from the CustomArray.
 * @details This function deletes elements from a CustomArray, checking that the size,
 *          capacity, and element shifting are correctly handled, and that the array
 *          resizes as needed.
 */
void testDeleteElement() {
    printf("testDeleteElement entered\n");
    CustomArray array;
    initArray(&array, 4);

    insertElement(&array, 1);
    insertElement(&array, 2);
    insertElement(&array, 3);
    insertElement(&array, 4);

    deleteElement(&array, 1);

    assert(array.size == 3);  // Ensure the size is updated correctly
    assert(array.data[1] == 3);  // Ensure the elements are shifted correctly

    deleteElement(&array, 0);
    deleteElement(&array, 0);
    deleteElement(&array, 0);

    assert(array.size == 0);  // Ensure the size is updated correctly
    assert(array.capacity == 2);  // Ensure the capacity is halved

    freeArray(&array);
    printf("testDeleteElement passed\n");
}

/**
 * @brief Test the access of elements in the CustomArray.
 * @details This function accesses elements in a CustomArray by index, checking that the
 *          correct elements are returned, and that out-of-bounds access is handled.
 */
void testGetElement() {
    CustomArray array;
    initArray(&array, 4);

    insertElement(&array, 1);
    insertElement(&array, 2);
    insertElement(&array, 3);

    assert(getElement(&array, 0) == 1);  // Ensure the correct element is returned
    assert(getElement(&array, 1) == 2);  // Ensure the correct element is returned
    assert(getElement(&array, 2) == 3);  // Ensure the correct element is returned
    assert(getElement(&array, 3) == -1);  // Ensure out of bounds returns -1

    freeArray(&array);
    printf("testGetElement passed\n");
}

/**
 * @brief Test the resizing of the CustomArray.
 * @details This function resizes a CustomArray to a new capacity and checks that the
 *          capacity is correctly updated, while the size remains unchanged.
 */
void testResizeArray() {
    CustomArray array;
    initArray(&array, 4);

    resizeArray(&array, 8);

    assert(array.capacity == 8);  // Ensure the capacity is updated correctly
    assert(array.size == 0);  // Ensure the size remains unchanged

    freeArray(&array);
    printf("testResizeArray passed\n");
}

/**
 * @brief Main function to run all tests.
 * @details This function calls all the test functions to ensure the
 *          CustomArray implementation works as expected.
 * @return int Returns 0 on successful execution of all tests.
 */
int main() {
    testInitArray();
    testInsertElement();
    testDeleteElement();
    testGetElement();
    testResizeArray();

    printf("All tests passed\n");
    return 0;
}
