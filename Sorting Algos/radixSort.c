/****************************************************************************************************************
*   WARNING: Before checking this sorting algorithm, you have to understand the counting sort algorithm first.  *  
*****************************************************************************************************************/
#include "Header_files/header.h"

#define SIZE 8

void display(int *arr, int size);
void radixSort(int *arr, int size);
void countingSort(int *arr, int size, int exp);

int main(void) {
    int inputArr[SIZE] = {170, 45, 75, 90, 802, 24, 2, 66};
    puts("Unsorted Array:");
    display(inputArr, SIZE);

    radixSort(inputArr, SIZE);
    puts("Sorted Array:");
    display(inputArr, SIZE);

    return 0;
}

void display(int *arr, int size) {
    int x;
    printf("{");
    for(x = 0; x < size; ++x) {
        printf("%d", arr[x]);
        if(x < size - 1) {
            printf(", ");
        }
    }
    printf("}\n\n");
}

void radixSort(int *arr, int size) {
    // Step 1: Get the max
    int x, max, xp;
    for(x = 0, max = 0; x < size; ++x) {
        max = (arr[x] > max) ? arr[x] : max;
    }

    // Step 2: Do counting sort for every digit 10^i, where i is the current digit no.
    for(xp = 1; (max / xp) > 0; xp *= 10) {
        countingSort(arr, size, xp);    // Refer to this function block after every iteration
    }

    // Step 10: The sorting is done!
}

void countingSort(int *arr, int size, int exp) {
    /*
    Step 3: Initialize a count array
    The count array for radix sort is dependent on the base (unlike the plain counting sort which is dependent on the largest element in the input array).
    For example, if you are sorting base-10 numbers (i.e., decimal system), the count array used in each digit pass will have a size of 10 (because each digit can range from 0 to 9).
    For this implementation, we're just sorting base-10 numbers, so the size of the count array will be 10.
    */
    int *countArr = (int*)calloc(10, sizeof(int));
    if (countArr == NULL) { puts("Memory allocation for countArr failed."); }   // Always check if the allocation is successful

    // Step 4: Store radix (or base) occurrences in the count array
    int x;
    for(x = 0; x < size; ++x) {
        countArr[(arr[x] / exp) % 10]++;
    }

    // Step 5: Store the cumulative sum in the count array
    for(x = 1; x < 10; ++x) {
        countArr[x] += countArr[x - 1];
    }

    // Step 6: Initialize an output array. The purpose of this is literally the same with the one used in counting sort.
    int *outputArr = (int*)calloc(size, sizeof(int));
    if (outputArr == NULL) { puts("Memory allocation for outputArr failed."); } // Always check if the allocation is successful

    // Step 7: Build the output array
    for(x = size - 1; x >= 0; --x) {
        outputArr[countArr[(arr[x] / exp) % 10] - 1] = arr[x];
        countArr[(arr[x] / exp) % 10]--;
    }

    // Step 8: Copy the contents from the output array to the input array
    for(x = 0; x < size; ++x) {
        arr[x] = outputArr[x];
    }

    // Step 9: Free the arrays allocated in the heap
    free(countArr);
    free(outputArr);
}