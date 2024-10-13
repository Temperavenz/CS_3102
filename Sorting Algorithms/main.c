#include "Definitions/defs.h"

int main(void) {
    int useMac, n, elemType, sortChoice, x;
    bool ifDups;

    // Use machine
    do {
        puts("Welcome to the Sorting Algorithms ATM!");
        puts("--------------------------------------");
        puts("Created by: Temporaven");
        puts("----------------------");
        printf("----------------------\n\n");

        // Transaction confirmation
        printf("Do you want to proceed with your transaction? (1) - Yes || (0) - No: ");
        scanf("%d", &useMac);

        // No. of elements confirmation
        do {
            printf("Please input the no. of elements you want to be sorted: ");
            scanf("%d", &n);
            if(n <= 1) {
                printf("Invalid. No. of elements must be greater than 1.\n\n");
            }
        }while(n <= 1);

        // Data type confirmation
        do {
            printf("Input (1) if you want to sort int no.s or (2) if you want to sort float no.s: ");
            scanf("%d", &elemType);
            if(elemType != 1 && elemType != 2) {
                printf("Invalid. Input must be either (1) or (2).\n\n");
            }
        }while(elemType != 1 && elemType != 2);

        // Data type to be sorted is int
        if(elemType == 1) {
            int *ipArr = (int*)malloc(n * sizeof(int));
            // Checks if all elements inputted are the same
            do {
                printf("Enter the elements to be sorted: ");
                for(x = 0; x < n; x++) {
                    scanf("%d", &ipArr[x]);
                }
                ifDups = checkDupsForInt(ipArr, n);
                if(ifDups) {
                    printf("All elements inputted are the same. Input at least one different element.\n\n");
                }
            }while(ifDups == true);

            // Sorting algorithm confirmation
            do {
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
                if(sortChoice < 1 || (sortChoice > 13 && sortChoice != 15)) {
                    printf("Invalid. Please select among the valid presented options.\n\n");
                }
            }while(sortChoice < 1 || (sortChoice > 13 && sortChoice != 15));

            switch(sortChoice) {
                case 1: bubbleSort(ipArr, n); break;
                case 2: insertionSort(ipArr, n); break;
                case 3: selectionSort(ipArr, n); break;
                case 4: shellSort(ipArr, n); break;
                case 5: combSort(ipArr, n); break;
                case 6: heapSort(ipArr, n); break;
                case 7: tournamentSort(ipArr, n); break;
                case 8: gnomeSort(ipArr, n); break;
                case 9: countingSort(ipArr, n); break;
                case 10: radixSort(ipArr, n); break;
                case 11: mergeSort(ipArr, 0, n - 1); break;
                case 12: quickSortLomuto(ipArr, 0, n - 1); break;
                case 13: quickSortHoare(ipArr, 0, n - 1); break;
                case 15: {
                    int *opArr = (int*)malloc(n * sizeof(int));
                    int opSize = 0;
                    strandSort(ipArr, n, opArr, &opSize);
                    // Display the transaction for choice 15 only
                    puts("-------------------------------------");
                    printf("Here is your completed transaction: ");
                    displayArr(opArr, n);
                    printf("-------------------------------------\n\n");
                    free(opArr);
                    break;
                }
            }

            // Display the transaction for choices 1 - 13
            if(sortChoice >= 1 || sortChoice <= 13) {
                puts("-------------------------------------");
                printf("Here is your completed transaction: ");
                displayArr(ipArr, n);
                printf("-------------------------------------\n\n");
                free(ipArr); 
            }

        // Data type to be sorted is float
        } else {
            float *fpArr = (float*)malloc(n * sizeof(float));
            do {
                printf("Enter the elements to be sorted: ");
                scanf("%f", &fpArr[x]);
                if(ifDups) {
                    printf("All elements inputted are the same. Input at least one different element.\n\n");
                }
            }while(ifDups == true);

            // Sorting algorithm confirmation
            do {
                puts("Sorting Algorithms available for use ::");
                puts("---------------------------------------");
                puts("(14) Bucket Sort");
                printf("Please input the no. of your choice: ");
                scanf("%d", &sortChoice);
                if(sortChoice != 14) {
                    printf("Invalid. Please select among the valid presented options.\n\n");
                }
            }while(sortChoice != 14);

            int *opBucc = bucketSort(fpArr, n);
            // Display the transaction for choice 14 only
            puts("-------------------------------------");
            printf("Here is your completed transaction: ");
            displayArr(opBucc, n);
            printf("-------------------------------------\n\n");
            free(opBucc);
            free(fpArr);
        }
        
        // Transaction done
        puts("===============================================");
        puts("Thank you for using the Sorting Algorithms ATM!");
        printf("===============================================\n\n");
    }while(useMac == 1);

    // No transaction done
    puts("===============================================");
    puts("Thank you for using the Sorting Algorithms ATM!");
    printf("===============================================\n\n");

    return 0;
}