#include "New_header_files/nhf.h"

#define SIZE 6

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

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

        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1, j = high + 1, temp;

    while(1) {
        do {
            i++;
        }while(arr[i] < pivot);

        do {
            j--;
        }while(arr[j] > pivot);

        if(i >= j) {
            return j;
        }

        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}