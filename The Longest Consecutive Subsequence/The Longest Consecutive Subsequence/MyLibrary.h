#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MaxarraySize 100
/* Description:
 * - This function takes a reference to an array of integers
 * - Sorts the array in ascending order
 * - Using the insertion sort algorithm
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns 0 if sorting is done without errors
 */
int8_t insertionSort(int32_t* array, uint8_t arraySize);

/* Description:
 * - This function takes a reference to an array of integers
 * - Prints all array elements
 * Return:
 * - Nothing to return
 */
void printArray(int32_t* array, uint8_t arraySize);

/* Description:
 * - This function takes a reference to an array,
 * - array size, and
 * - reference to store the size of the LCS
 * - Using the insertion sort algorithm
 * - The function will search for the LCS in the array and
 * - stores its size
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns -3 if there is no LCS,
 * (i.e all array elements are not consecutive at all)
 * - returns 0 otherwise
 */
int8_t lcsGetSize(int32_t* array, uint8_t arraySize, uint8_t* sizeofLCS);

/* Description:
 * - This function takes a reference to the input array which stores the the entered string of the user,
 * - array to copy the data after validating and converting the it to integer,
 * - reference to store the size of the date copied to the Integer array
 * - The function will search integers between  [ ] and starts converting the string to integer for further processing
 * - stores the size of the data copied
 * Return:
 * - returns -1 if the array is empty
 * - returns 0 otherwise
 */
int8_t getExpression(char* inputArray, int32_t* array, uint8_t* n);
