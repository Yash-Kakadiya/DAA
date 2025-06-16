#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

void write_best_case()
{
    char fileName[50];
    sprintf(fileName, "best_case_%d.txt", N);

    FILE *fp = fopen(fileName, "w");

    for (int i = 1; i <= N; i++)
    {
        fprintf(fp, "%d ", i);
    }
    fclose(fp);
}
void write_worst_case()
{
    char fileName[50];
    sprintf(fileName, "worst_case_%d.txt", N);

    FILE *fp = fopen(fileName, "w");

    for (int i = N; i >= 1; i--)
    {
        fprintf(fp, "%d ", i);
    }
    fclose(fp);
}
void write_average_case()
{
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }

    // Suffle Array
    srand(time(NULL));
    for (int i = N - 1; i >= 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    char fileName[50];
    sprintf(fileName, "average_case_%d.txt", N);

    FILE *fp = fopen(fileName, "w");

    for (int i = 0; i < N; i++)
    {
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);
}

void main()
{
    write_best_case();
    write_worst_case();
    write_average_case();
}