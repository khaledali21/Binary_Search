#include "main.h"



void main(void){

   uint32_t au32_arr[MAX_SIZE];
   uint8_t u8_size;
   uint32_t u32_number;
   printf("Please Enter the size of the array: ");
   scanf("%d", &u8_size);
   printf("Please Enter the values of the array: ");
   for(uint8_t u8_index = 0; u8_index < u8_size; u8_index++){
      scanf("%d", &au32_arr[u8_index]);
   }
   printf("\nPlease Enter the value you are searching for: ");
   scanf("%d", &u32_number);
   uint8_t u8_foundAt = binarySearch(au32_arr, u8_size, u32_number);
   if(u8_foundAt == MAX_SIZE){
      printf("Value not found.\n");
   }
   else{
      printf("Value found at index: %d\n", u8_foundAt);
   }
}
/*
* brief: This function uses binary search to find the index of the required value
* param.: (input) a pointer to the array containing the elements
* param.: (input) size of the filled part of the array
* param.: (input) the number required to find its index
* return: (output) the array index with the required value or the Max size of the array if element not found
*/
uint8_t binarySearch(uint32_t* pu32_arr, uint8_t u8_size, uint32_t u32_number){
   if(!isSorted(pu32_arr, u8_size)){
      sorting(pu32_arr, u8_size);
   }
   uint8_t low = 0, high = u8_size - 1;
   uint8_t mid = low + (high - low)/2;
   while(low < high){
      if(pu32_arr[mid] == u32_number){
         return mid;
      }
      else if(pu32_arr[mid] > u32_number){
         high = mid - 1;
      }
      else{
         low = mid + 1;
      }
      mid = low + (high - low) / 2;
   }
   if(pu32_arr[mid] == u32_number)
   {
      return mid;
   }
   else{
      return MAX_SIZE;
   }
}
/*
* brief: This function uses bubble sort to sort the array
* param.: (input) a pointer to the array containing the elements
* param.: (input) size of the filled part of the array
*/
void sorting(uint32_t* pu32_arr, uint8_t u8_size){
   for(uint8_t u8_findex = 0; u8_findex < u8_size - 1; u8_findex++){
      for(uint8_t u8_sindex = 0; u8_sindex < u8_size - u8_findex - 1; u8_sindex++){
         if(pu32_arr[u8_sindex] > pu32_arr[u8_sindex + 1]){
            swap(&pu32_arr[u8_sindex], &pu32_arr[u8_sindex + 1]);
         }
      }
   }
}
/*
* brief: This function checks wether the array is sorted or not
* param.: (input) a pointer to the array containing the elements
* param.: (input) size of the filled part of the array
* return: (output) return 1 if the array is sorted and 0 otherwise
*/
uint8_t isSorted(uint32_t* pu32_arr, uint8_t u8_size){
   for(uint8_t u8_index = 1; u8_index < u8_size; u8_index++){
      if(pu32_arr[u8_index] < pu32_arr[u8_index - 1]){
         return 0;
      }
   }
   return 1;
}
/*
* brief: This function swaps 2 values
* param.: (input) a pointer to the first value
* param.: (input) a pointer to the second value
*/
void swap(uint32_t* pu32_first, uint32_t* pu32_second){
   uint32_t u32_temp = *pu32_first;
   *pu32_first = *pu32_second;
   *pu32_second = u32_temp;
}