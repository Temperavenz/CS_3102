#include "Definitions/defs.h"

int main(void) {
    int n;
    printf("Enter no. of elements to be sorted: ");
    scanf("%d", &n);

    int opt;
    printf("Are the elements int or float? (1) int || (2) float: ");

    int choice, n, elemType, sortChoice;
    do {
        puts("Welcome to the Sorting Algorithms machine!");
        printf("------------------------------------------\n\n");
        printf("Do you want to proceed with your transaction? (1) - Yes || (0) - No: ");
        puts("");

        printf("Please input the no. of elements you want to be sorted: ");
        scanf("%d", &n);
        puts("");

        printf("Input (1) if you want to sort int no.s or (2) if you want to sort float no.s: ");
        scanf("%d", &elemType);
        puts("");

        if(elemType == 1) {
            int *intArr = (int*)malloc(n * sizeof(int));
            puts("Sorting Algorithms available for use ::");
            puts("---------------------------------------");
            puts("(1) Bubble Sort\t\t(2) Insertion Sort");
            puts("(3) Selection Sort\t\t(4) Shell Sort");
            puts("(5) Comb Sort\t\t(6) Heap Sort");
            puts("(7) Tournament Sort\t\t(8) Gnome Sort");
            puts("(9) Counting Sort\t\t(10) Radix Sort");
            puts("(11) Merge Sort\t\t(12) Quick Sort (Lomuto)");
            puts("(13) Quick Sort (Hoare)\t\t(15) Strand Sort");
            printf("Please input the no. of your choice: ");
            scanf("%d", &sortChoice);
            switch(sortChoice) {
                case 1: bubbleSort(intArr, n);
                        displayArr(intArr, n);
                        break;
                case 2: insertionSort(intArr, n);
                        displayArr(intArr, n);
                        break;
                case 3: selectionSort(intArr, n);
                        displayArr(intArr, n);
                        break;
                case 4: shellSort(intArr, n);
                        displayArr(intArr, n);
                        break;
                case 5: combSort(intArr, n);
                        displayArr(intArr, n);
                        break;
                case 6: heapSort(intArr, n);
                        displayArr(intArr, n);
                        break;
                case 7: tournamentSort(intArr, n);
                        displayArr(intArr, n);
                        break;
                case 8: gnomeSort(intArr, n);
                        displayArr(intArr, n);
                        break;
                case 9: countingSort(intArr, n);
                        displayArr(intArr, n);
                        break;
                case 10: radixSort(intArr, n);
                         displayArr(intArr, n);
                         break;
                case 11: mergeSort(intArr, 0, n - 1);
                         displayArr(intArr, n);
                         break;
                case 12: quickSortLomuto(intArr, 0, n - 1);
                         displayArr(intArr, n);
                         break;
                case 13: quickSortHoare(intArr, 0, n - 1);
                         displayArr(intArr, n);
                         break;
                case 15:
                         int *opArr = (int*)malloc(n * sizeof(int));
                         int opSize = 0;
                         strandSort(intArr, n, opArr, &opSize);
                         displayArr(opArr, n);
                         free(opArr);
                         break;
                default: puts("Invalid Choice.");
                         break;
            }
            free(intArr);
        } else {
            float *floArr = (float*)malloc(n * sizeof(float));
            puts("Sorting Algorithms available for use ::");
            puts("---------------------------------------");
            puts("(14) Bucket Sort");
            printf("Please input the no. of your choice: ");
            scanf("%d", &sortChoice);
            if(sortChoice == 14) {
                int *opBucc = bucketSort(floArr, n);
                displayArr(opBucc, n);
            } else {
                puts("Invalid Choice.");
            }
            free(floArr);
        }
    }while(choice > 0);
    puts("Thank you for using the Sorting Algorithms machine!");

    return 0;
}