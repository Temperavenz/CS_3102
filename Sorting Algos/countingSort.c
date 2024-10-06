#include "Header_files/header.h"

#define SIZE 8

void display(int *arr, int size);
void countingSort(int *arr, int size);

int main(void) {
    int inputArr[SIZE]={4, 3, 12, 1, 5, 5, 3, 9};
    puts("Unsorted Array:");
    display(inputArr, SIZE);

    countingSort(inputArr, SIZE);
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

void countingSort(int *arr, int size) {
    // Step 1: Find the maximum element from the input array
    int x, max;
    for(x = 0, max = 0; x < size; ++x) {
        max = (arr[x] > max) ? arr[x] : max;
    }

    /*
    Step 2: Initialize a count array of length max+1 w/ all elems as 0
    This array is used for storing the occurrences
    */
    int *countArr = (int*)calloc(max + 1, sizeof(int));
    if(countArr == NULL) { puts("countArr allocation failed."); }   // Always check if the allocation is successful

    /*
    Step 3: Store the occurrences in the count array
    (the elems inside the input array is the indices in where to store the occurrences in the count array)
    */
    for(x = 0; x < size; ++x) {
        countArr[arr[x]]++;
    }

    // Step 4: Store the cumulative sum/prefix sum in the count array
    for(x = 1; x <= max; ++x) {
        countArr[x] += countArr[x - 1];
    }

    /*
    Step 5: Initialize an output array
    This array will be used to store the sorted order of elems,
    which is to be transferred to the input array
    */
    int *outputArr = (int*)malloc(size * sizeof(int));
    if(countArr == NULL) { puts("outputArr allocation failed."); }  // Always check if the allocation is successful

    // Step 6: Commence the sorting
    for(x = size - 1; x >= 0; --x) {
        outputArr[countArr[arr[x]] - 1] = arr[x];
        countArr[arr[x]]--;
    }

    // Step 7: Transfer the contents of the output array to the input array
    for(x = 0; x < size; ++x) {
        arr[x] = outputArr[x];
    }

    // Step 8: The sorting is done! Just free the arrays allocated in the heap
    free(countArr);
    free(outputArr);
}