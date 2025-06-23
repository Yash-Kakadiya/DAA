#include <stdio.h>
#include <time.h>
#include "sorting.h"

void readFile(const char *filename, int arr[], int n)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (fscanf(file, "%d", &arr[i]) != 1)
        {
            fprintf(stderr, "Error reading data from file\n");
            fclose(file);
            return;
        }
    }
    fclose(file);
}

void measureTime(void (*sortFunc)(int[], int), int arr[], int n)
{
    clock_t start = clock();
    sortFunc(arr, n);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_spent);
}

void main()
{
    int arraySizes[] = {100, 1000, 10000, 100000};
    char *cases[] = {"best", "average", "worst"};
    while (1)
    {

        printf("Choose sorting technique:\n");
        printf("0. Bubble Sort\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Heap Sort\n");
        printf("Enter your choice: ");
        int sortChoice;
        scanf("%d", &sortChoice);

        printf("Choose case:\n");
        printf("0. Best Case\n");
        printf("1. Worst Case\n");
        printf("2. Average Case\n");
        printf("Enter your choice: ");
        int caseChoice;
        scanf("%d", &caseChoice);

        printf("Choose N (size of array): ");
        printf("0. 100\n");
        printf("1. 1000\n");
        printf("2. 10000\n");
        printf("3. 100000\n");
        int sizeChoice;
        scanf("%d", &sizeChoice);
        int n = arraySizes[sizeChoice];
        int arr[n];

        char filename[50];
        sprintf(filename, "%s_case_%d.txt", cases[caseChoice], arraySizes[n]);
        readFile(filename, arr, n);

        printf("Sorting %s case with N = %d using ", cases[caseChoice], arraySizes[n]);
        switch (sortChoice)
        {
        case 0:
            printf("Bubble Sort...\n");
            measureTime(bubbleSort, arr, n);
            break;
        case 1:
            printf("Insertion Sort...\n");
            measureTime(insertionSort, arr, n);
            break;
        case 2:
            printf("Selection Sort...\n");
            measureTime(selectionSort, arr, n);
            break;
        case 3:
            printf("Heap Sort...\n");
            measureTime(heapSort, arr, n);
            break;
        default:
            return;
        }
        printf("Sorting completed.\n");
    }
}