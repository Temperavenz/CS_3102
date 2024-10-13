#ifndef SORT_DEF
#define SORT_DEF

#include "../Prototypes/protos.h"

/********************************
*   Part A Function Definitions *
*********************************/
void bubbleSort(int arr[], int size) {
    // Insert code here
}

void insertionSort(int arr[], int size) {
    // Insert code here
}

void selectionSort(int arr[], int size) {
    // Insert code here
}

void shellSort(int arr[], int size) {
    // Insert code here
}

void combSort(int arr[], int size) {
    // Insert code here
}

void heapSort(int arr[], int size) {
    // Insert code here
}
void maxHeapify(int arr[], int node) {
    // Insert code here
}
void deleteMax(int arr[], int node) {
    // Insert code here
}

void tournamentSort(int arr[], int size) {
    // Insert code here
}

/********************************
*   Part B Function Definitions *
*********************************/
void gnomeSort(int arr[], int size) {
    // Insert code here
}

void countingSort(int arr[], int size) {
    // Insert code here
}

void radixSort(int arr[], int size) {
    // Insert code here
}
void countingRadix(int arr[], int size) {
    // Insert code here
}

void mergeSort(int arr[], int leftIdx, int rightIdx) {
    // Insert code here
}
void merge(int arr[], int leftIdx, int midIdx, int rightIdx) {
    // Insert code here
}

void quickSortLomuto(int arr[], int low, int high) {
    // Insert code here
}
void lomutoPartition(int arr[], int low, int high) {
    // Insert code here
}

void quickSortHoare(int arr[], int low, int high) {
    // Insert code here
}
void hoarePartition(int arr[], int low, int high) {
    // Insert code here
}

int *bucketSort(float arr[], int size) {
    // Insert code here
}
void insertSorted(List *buckets, float elem) {
    // Insert code here
}

void strandSort(int ipArr[], int ipSize, int opArr[], int *opSize) {
    // Insert code here
}
void strandMerge(int tempArr[], int tempSize, int sublist[], int subSize, int opArr[]) {
    // Insert code here
}

// Miscellaneous function definitions
void displayArr(int arr[], int size) {
    // Insert code here
    int x;
    printf("[");
    for(x = 0; x < size; x++) {
        printf("%d", arr[x]);
        if(x < size - 1) {
            printf(", ");
        }
    }
    printf("]\n\n");
}

bool checkDupsForInt(int arr[], int size) {
    // Insert code here
    bool checker = false;
    int x;
    for(x = 0; x < size - 1 && checker == false; x++) {
        checker = (arr[x] == arr[x + 1]) ? false : true;
    }
    return checker;
}

bool checkDupsForFlo(float arr[], int size) {
    // Insert code here
    bool checker = false;
    int x;
    for(x = 0; x < size - 1 && checker == false; x++) {
        checker = (arr[x] == arr[x + 1]) ? false : true;
    }
    return checker;
}

#endif