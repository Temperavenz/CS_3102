#include "Header_files/header.h"

void insertionSort(int *arr, int size);
void display(int *arr, int size);

int main(void) {
    Data D={2, 5, 7, 9, 6, 1, 3, 8, 4, 10};
    insertionSort(D, ARR_SIZE);
    display(D, ARR_SIZE);

    return 0;
}

void insertionSort(int *arr, int size) {
    int x, y, temp;
    for(x=1; x<size; ++x) {
        for(y=x; y>0&&arr[y]<arr[y-1]; --y) {
            temp=arr[y-1];
            arr[y-1]=arr[y];
            arr[y]=temp;
        }
    }
}

void display(int *arr, int size) {
    int x;
    printf("{");
    for(x=0; x<size; ++x) {
        printf("%d", arr[x]);
        if(x<size-1) {
            printf(", ");
        }
    }
    puts("}");
}