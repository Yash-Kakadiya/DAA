#include <stdio.h>
#include <time.h>

int linearSearch(int *arr, int n, int target)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

int binarySearch(int *arr, int n, int target)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

void main()
{
    int target;
    printf("Enter the number: ");
    scanf("%d", &target);

    FILE *file = fopen("../Arrays/average_case_100.txt", "r");
    if (file == NULL)
    {
        printf("Could not open file %s\n", "../Arrays/average_case_100.txt");
        fclose(file);
        return;
    }
    int n = 100;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    clock_t start, end;
    int result;
    double time_taken;

    start = clock();
    result = linearSearch(arr, n, target);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Linear Search:\n Element Index:%d\nTime Taken: %f", result, time_taken);

    start = clock();
    result = binarySearch(arr, n, target);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Binary Search:\n Element Index:%d\nTime Taken: %f", result, time_taken);
}