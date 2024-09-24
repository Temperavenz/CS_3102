#include "Header_files/header.h"

void bubbleSort(int *arr, int size);
void display(int *arr, int size);

int main(void) {
    Data D={2, 5, 7, 9, 6, 1, 3, 8, 4, 10};
    bubbleSort(D, ARR_SIZE);
    display(D, ARR_SIZE);

    return 0;
}

void bubbleSort(int *arr, int size) {
    int x, y, temp, n;
    for(x=0; x<size-1; ++x) {
        for(y=0; y<size; ++y) {
            if(arr[y+1]<arr[y]&&y<size-1) {
                temp=arr[y];
                arr[y]=arr[y+1];
                arr[y+1]=temp;
            }
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