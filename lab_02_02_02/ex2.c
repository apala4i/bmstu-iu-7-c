#include <stdio.h>

#define INPUT_ERROR 1
#define ARRAY_SIZE_ERROR 2
#define ARRAY_INPUT_ERROR 3
#define NO_SUITABLE_ELEMENTS_ERROR 4

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

int equal_beg_end_l(int *array, int n, int *new_len)
{
    int first_digit;
    for (int i = 0; i < n; i++)
    {
        first_digit = array[i];
        while ((first_digit > 9) || ((first_digit * (-1)) > 9))
            first_digit /= 10;
        if (first_digit == (array[i] % 10))
            *new_len += 1;
    }
    if (!*new_len)
        return 1;
    return 0;
}

void equal_beg_end(int *array, int n, int *new_array)
{
    int current = 0;
    int first_digit;
    for (int i = 0; i < n; i++)
    {
        first_digit = array[i];
        while ((first_digit > 9) || ((first_digit * (-1)) > 9))
            first_digit /= 10;
        if (first_digit == (array[i] % 10))
            new_array[current++] = array[i];
    }
}

void print_array(int *array, int new_len)
{
    for (int i = 0; i < new_len; i++)
        printf("%d ", array[i]);
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

    if (array_input(array, n) == 1)
    {
        printf("Array input error.");
        return ARRAY_INPUT_ERROR;
    }

    int new_len = 0;

    if (equal_beg_end_l(array, n, &new_len) == 1)
    {
        printf("There is no suitable elements.");
        return NO_SUITABLE_ELEMENTS_ERROR;
    }
    int new_array[10];
    equal_beg_end(array, n, new_array);
    print_array(new_array, new_len);

    return 0;
}