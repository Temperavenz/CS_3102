#include "Header_files/header.h"

void gnomeSort(int *arr, int size);
void display(int *arr, int size);

int main(void) {
    Data D={9, 3, 1, 5, 7, 4, 10, 8, 6, 2};
    gnomeSort(D, ARR_SIZE);
    display(D, ARR_SIZE);

    return 0;
}

void gnomeSort(int *arr, int size) {
    int x, temp;
    for(x=0; x<size-1; ++x) {
        while(arr[x+1]<arr[x]) {
            temp=arr[x];
            arr[x]=arr[x+1];
            arr[x+1]=temp;
            x=(x>0)?x-1:x;
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