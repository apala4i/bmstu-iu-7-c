#include "libkey_func.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst, int *count)
{
    if (pb_src == NULL || pe_src == NULL || pe_src - pb_src <= 0)
    {
        return INPUT_ERROR;
    }
    const int *new_end = pe_src - 1;
    while (new_end > pb_src && *new_end >= 0)
        new_end--;

    if (new_end == pb_src)
    {
        if (*new_end < 0)
        {
            return EMPTY_RESULT;
        }
        else
            new_end = pe_src;
    }

    if (*pb_dst == NULL)
    {
        *count = (int)(new_end - pb_src);
        return EXIT_SUCCESS;
    }

    *pe_dst = *pb_dst;
    for (const int *current = pb_src; current < new_end; ++current)
    {
        **pe_dst = *current;
        (*pe_dst)++;
    }
    return EXIT_SUCCESS;
}