#include <stdio.h>

#define STABLE_WORK 0
#define INPUT_ERROR 1
#define ARRAY_SIZE_ERROR 2
#define NO_POSITIVE_OR_NEGATIVE_ERROR 4

int pos_checker(int *begin, int *end)
{
    while (begin != end)
    {
        if (*begin > 0)
            return STABLE_WORK;
        begin += 1;
    }
    return NO_POSITIVE_OR_NEGATIVE_ERROR;
}

int neg_checker(int *begin, int *end)
{
    while (begin != end)
    {
        if (*begin < 0)
            return 0;
        begin += 1;
    }
    return NO_POSITIVE_OR_NEGATIVE_ERROR;
}

int array_input(int *begin, int *end)
{
    while (begin != end)
    {
        if (scanf("%d", begin) != 1)
            return INPUT_ERROR;
        begin += 1;
    }
    return STABLE_WORK;
}

void multiply_counter(int *begin, int *end, int *multiply)
{
    int *fixed_begin = begin;
    int *fixed_end = end;
    while ((begin <= fixed_end) && (end >= fixed_begin))
    {
        while ((*begin >= 0) && (begin < fixed_end))
            begin++;
        while ((*end <= 0) && (end > fixed_begin))
            end--;
        if ((*begin < 0) && (*end > 0))
            *multiply += (*begin) * (*end);
        begin++;
        end--;
    }
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
    int *begin = array;
    int *end = array + n;
    if (array_input(begin, end))
    {
        printf("INPUT_ERROR");
        return INPUT_ERROR;
    }
    if (neg_checker(begin, end) || pos_checker(begin, end))
    {
        printf("NO_POSITIVE_OR_NEGATIVE_ERROR");
        return NO_POSITIVE_OR_NEGATIVE_ERROR;
    }
    int multiply = 0;
    multiply_counter(begin, end - 1, &multiply);
    printf("%d", multiply);
    return STABLE_WORK;
}