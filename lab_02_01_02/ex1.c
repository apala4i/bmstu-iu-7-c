#include <stdio.h>

#define INPUT_ERROR 1
#define ARRAY_SIZE_ERROR 2
#define ARRAY_INPUT_ERROR 3
#define ONLY_POSITIVE_ERROR 4

int negative_average(int *arr, int n, double *average)
{
    double sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] < 0)
        {
            sum += arr[i];
            count++;
        }
    if (count == 0)
        return 1;
    else
    {
        *average = sum / count;
        return 0;
    }
}

int array_input(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Input array error");
            return 1;
        }
    }

    return 0;
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1)
    {
        printf("Input error.");
        return INPUT_ERROR;
    }

    if ((n > 10) || (n <= 0))
    {
        printf("Array size error.");
        return ARRAY_SIZE_ERROR;
    }
    int array[10];
    double average;

    if (array_input(array, n) == 1)
    {
        printf("Array input error.");
        return ARRAY_INPUT_ERROR;
    }

    if (negative_average(array, n, &average) == 1)
    {
        printf("There is no negative elements.");
        return ONLY_POSITIVE_ERROR;
    }
    printf("Average negative = %.6lf", average);

    return 0;
}