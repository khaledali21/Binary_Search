#ifndef __MAIN__
#define __MAIN__
#include <stdio.h>
#include <stdint.h>

#define MAX_SIZE 255
uint8_t binarySearch(uint32_t* arr, uint8_t size, uint32_t number);
void sorting(uint32_t* arr, uint8_t size);
uint8_t isSorted(uint32_t* arr, uint8_t size);
void swap(uint32_t* first, uint32_t* second);
#endif