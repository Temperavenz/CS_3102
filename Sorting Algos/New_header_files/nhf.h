#ifndef PREBUILT_SF
#define PREBUILT_SF

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Pre-built prototypes
void display(int arr[], int size);

// Pre-built definitions
void display(int arr[], int size)
{
    int x;
    printf("{");
    for(x = 0; x < size; ++x) {
        printf("%d", arr[x]);
        if(x < size - 1) {
            printf(", ");
        }
    }
    printf("}\n\n");
}

#endif