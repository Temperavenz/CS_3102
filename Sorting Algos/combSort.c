#include "Header_files/header.h"

void combSort(int *arr, int size);
void display(int *arr, int size);

int main(void) {
    Data D={3, 10, 5, 7, 4, 9, 1, 6, 8, 2};
    combSort(D, ARR_SIZE);
    display(D, ARR_SIZE);

    return 0;
}

void combSort(int *arr, int size) {
    int x, y, temp;
    bool swapped;
    for(x=size/1.3, swapped=1; x>0||swapped==1; x/=1.3) {
        swapped=0;
        for(y=0; y<size-x; ++y) {
            if(arr[y]>arr[y+x]) {
                temp=arr[y];
                arr[y]=arr[y+x];
                arr[y+x]=temp;
                swapped=1;
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