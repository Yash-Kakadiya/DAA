#include <stdio.h>

void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
}

void insertion_sort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(int *arr, int n)
{

    // Traverse through all array elements from 0 to length-1
    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in remaining unsorted array
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        // Swap the minimum element with the current element at index 'i'
        if (minIdx != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

void heap_sort(int *arr, int n)
{
    build_max_heap(arr, n);
    for (int i = n - 1; i > 0; i++)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void build_max_heap(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
void heapify(int *arr, int n, int i)
{
    int maxIdx = i;                // Initialize largest as root
    int leftChildIdx = 2 * i + 1;  // left child
    int rigthChildIdx = 2 * i + 2; // right child

    // If left child is larger than root
    if (leftChildIdx < n && arr[leftChildIdx] > arr[maxIdx])
    {
        maxIdx = leftChildIdx;
    }

    // If right child is largest
    if (rigthChildIdx < n && arr[rigthChildIdx] > arr[maxIdx])
    {
        maxIdx = rigthChildIdx;
    }

    // If largest is not root
    if (i != maxIdx)
    {
        // swap
        int temp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, maxIdx);
    }
}

void merge_sort(int *arr, int n)
{
    int low = 0;
    int high = n - 1;
    mergeSortHelper(low, high, arr);
}
void mergeSortHelper(int low, int high, int *arr)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSortHelper(low, mid, arr);
        mergeSortHelper(mid + 1, high, arr);
        merge(low, mid, high, arr);
    }
}

void merge(int low, int mid, int high, int *arr)
{

    int localArr[high + 1];
    int leftIdx = low, rightIdx = mid + 1, localI = low;

    // merge two arrays
    while (leftIdx <= mid && rightIdx <= high)
    {
        if (arr[leftIdx] <= arr[rightIdx])
        {
            localArr[localI] = arr[leftIdx++];
        }
        else
        {
            localArr[localI] = arr[rightIdx++];
        }
        localI++;
    }

    // Copy remaining elements of right array, if any
    if (leftIdx > mid)
    {
        for (int k = rightIdx; k <= high; k++)
        {
            localArr[localI++] = arr[k];
        }
    }
    else
    {
        // Copy remaining elements of left array, if any
        for (int k = leftIdx; k <= mid; k++)
        {
            localArr[localI++] = arr[k];
        }
    }

    // Copy the sorted elements to original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = localArr[i];
    }
}

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {

        printf("%d, ", arr[i]);
    }
}

int main()
{
    int arr[] = {
        64,
        34,
        25,
        12,
        22,
    };
    int n = sizeof(arr) / sizeof(arr[0]);
    // bubble_sort(arr, n);
    // insertion_sort(arr, n);
    // selection_sort(arr, n);
    // heap_sort(arr, n);
    merge_sort(arr, n);
    printf("ok");
    print_array(arr, n);

    return 1;
}