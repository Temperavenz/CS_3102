#include "Header_files/header.h"

void selectionSort(int *arr, int size);
void display(int *arr, int size);

int main(void) {
    Data D={2, 5, 7, 9, 6, 1, 3, 8, 4, 10};
    selectionSort(D, ARR_SIZE);
    display(D, ARR_SIZE);

    return 0;
}

void selectionSort(int *arr, int size) {
    int x, y, min, temp;
    for(x=0; x<size-1; ++x) {
        for(y=x, min=x; y<size; ++y) {
            if(arr[y]<arr[min]) {
                min=y;
            }
        }
        if(min!=x) {
            temp=arr[x];
            arr[x]=arr[min];
            arr[min]=temp;
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