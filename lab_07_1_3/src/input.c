#include "../inc/input.h"

int digits_counter(const char *file_name, int *count)
{
    // try to open the file
    FILE *input_file = fopen(file_name, "r");

    // check that file was opened
    if (input_file == NULL)
        return FILE_DOES_NOT_EXIST;

    int helper;
    // counting digits
    while (fscanf(input_file, "%d", &helper) == 1)
        (*count)++;

    // check that nothing is missing
    if (!feof(input_file))
    {
        fclose(input_file);
        return INPUT_ERROR;
    }

    if (*count == 0)
    {
        fclose(input_file);
        return EMPTY_FILE;
    }

    fclose(input_file);
    return EXIT_SUCCESS;
}

int make_and_fill(const char *file_name, const int count, int **arr_begin, int **arr_end)
{
    // try to open file
    FILE *input_file = fopen(file_name, "r");

    // check its existing
    if (input_file == NULL)
        return FILE_DOES_NOT_EXIST;

    // memory for new arr
    *arr_begin = malloc(count * sizeof(int));
    if (*arr_begin == NULL)
    {
        free(arr_begin);
        fclose(input_file);
        return MEM_ERROR;
    }
    *arr_end = *arr_begin + count;

    for (int *current = *arr_begin; current != *arr_end; ++current)
    {
        fscanf(input_file, "%d", current);
    }
    return EXIT_SUCCESS;
}