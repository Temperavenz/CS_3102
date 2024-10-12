#ifndef SORT_PROTO
#define SORT_PROTO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/************************
*   Linked-List Build   *
*************************/
typedef struct node {
    float data;
    struct node *link;
}*List;

/*  ==================================================================================  */

/********************************
*   Part A Function Prototypes  *
*********************************/
void bubbleSort(int arr[], int size);

void insertionSort(int arr[], int size);

void selectionSort(int arr[], int size);

void shellSort(int arr[], int size);

void combSort(int arr[], int size);

void heapSort(int arr[], int size);
void maxHeapify(int arr[], int node);
void deleteMax(int arr[], int node);

void tournamentSort(int arr[], int size);

/********************************
*   Part B Function Prototypes  *
*********************************/
void gnomeSort(int arr[], int size);

void countingSort(int arr[], int size);

void radixSort(int arr[], int size);
void countingRadix(int arr[], int size);

void mergeSort(int arr[], int leftIdx, int rightIdx);
void merge(int arr[], int leftIdx, int midIdx, int rightIdx);

void quickSortLomuto(int arr[], int low, int high);
void lomutoPartition(int arr[], int low, int high);

void quickSortHoare(int arr[], int low, int high);
void hoarePartition(int arr[], int low, int high);

int *bucketSort(float arr[], int size);
void insertSorted(List *buckets, float elem);

void strandSort(int ipArr[], int ipSize, int opArr[], int *opSize);
void strandMerge(int tempArr[], int tempSize, int sublist[], int subSize, int opArr[]);

// Display function prototype
void displayArr(int arr[], int size);

#endif