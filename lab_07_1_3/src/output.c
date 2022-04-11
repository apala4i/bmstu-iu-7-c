#include "../inc/output.h"

int print_to_file(const int *arr_begin, const int *arr_end, const char *file_name)
{
    FILE *output_file = fopen(file_name, "w");
    if (output_file == NULL)
        return UNABLE_TO_CREATE_FILE;
    for (const int *current = arr_begin; current != arr_end; ++current)
    {
        fprintf(output_file, "%d ", *current);
    }
    fclose(output_file);
    return EXIT_SUCCESS;
}