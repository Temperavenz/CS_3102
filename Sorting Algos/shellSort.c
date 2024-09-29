#include "Header_files/header.h"

void shellSort(int *arr, int size);
void display(int *arr, int size);

int main(void) {
    Data D={3, 10, 5, 7, 4, 9, 1, 6, 8, 2};
    shellSort(D, ARR_SIZE);
    display(D, ARR_SIZE);

    return 0;
}

void shellSort(int *arr, int size) {
    int x, y, z, temp;
    for(x=size/2; x>0; x/=2) {
        for(y=x; y<size; ++y) {
            for(z=y; z>=x&&arr[z-x]>arr[z]; z-=x) {
                temp=arr[z-x];
                arr[z-x]=arr[z];
                arr[z]=temp;
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