#include "New_header_files/nhf.h"

#define SIZE 6

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);

int main(void) {
    int ipArr[SIZE] = {10, 7, 8, 9, 1, 5};
    puts("Unsorted Array ::");
    puts("-----------------");
    display(ipArr, SIZE);

    quickSort(ipArr, 0, SIZE - 1);
    puts("Sorted Array ::");
    puts("---------------");
    display(ipArr, SIZE);

    return 0;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1, j;

    for(j = low; j <= high - 1; ++j) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}