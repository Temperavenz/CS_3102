#include "Header_files/header.h"

void bubbleSort(int *arr, int size);
void display(int *arr, int size);

int main(void) {
    return 0;
}

void bubbleSort(int *arr, int size) {
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