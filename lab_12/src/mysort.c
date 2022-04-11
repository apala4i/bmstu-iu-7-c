#include "mysort.h"




void swap(void *first, void *second, size_t size)
{
    char tmp;
    for (size_t i = 0; i < size; ++i)
    {
        tmp = *((char *) first + i);
        *((char *) first + i) = *((char *) second + i);
        *((char *) second + i) = tmp;
    }
}

void *next(void *value, size_t size)
{
    return (char *) value + size;
}

void *prev(void *value, size_t size)
{
    return (char *) value - size;
}

int mysort(void *first, int number, size_t size, int (*comparator)(const void *, const void *))
{
    if (number < 1)
        return EMPTY_SEQUENCE;

    if (first == NULL)
    {
        return NULL_ERROR;
    }

    if (number == 1)
        return EXIT_SUCCESS;

    void *end = (char *) first + size * number;


    for (void *current = next(first, size); current != end; current = next(current, size))
    {
        void *temp = current;
        while (temp != first && comparator(prev(temp, size), temp) > 0)
        {
            swap(temp, prev(temp, size), size);
            temp = prev(temp, size);
        }
    }
    return EXIT_SUCCESS;
}

int comp_for_int(const void *first, const void *second)
{
    return *((int *) first) - *((int *) second);
}

int comp_for_char(const void *first, const void *second)
{
    return *((char *) first) - *((char *) second);
}

int comp_for_float(const void *first, const void *second)
{
    return (int) (*((float *) first) - *((float *) second));
}