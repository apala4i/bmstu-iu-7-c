#include "matrix.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>

int comp_for_int(const void *first, const void *second)
{
    return  *(int *)first - *(int *)second;
}

int main(int argc, char *argv[])
{
    int rc = 0;
    int *res_arr = NULL;
    matrix test;
    matrix_init(&test);
    if (argc == 2)
    {
        FILE *flow = fopen(argv[1], "r");
        if (flow == NULL)
        {
            rc = FILE_ERROR;
        }
        else
        {
            rc = read_matrix(flow, &test);
            fclose(flow);
            if (!rc)
            {
                int count;
                count = matrix_process_count(&test);

                if (count != 0)
                {
                    res_arr = malloc(sizeof(int) * count);
                    if (res_arr == NULL)
                    {
                        rc = MEM_ERROR;
                    }
                    else
                    {
                        matrix_process_fill(&test, res_arr);
                        qsort(res_arr, count, sizeof(int), comp_for_int);
                        matrix_process_fill_back(&test, res_arr);
                        print_matrix(stdout, &test);
                    }
                } else
                {
                    rc = NO_OUTPUT;
                    printf("Нет подходящих элементов!\n");
                }
            }
        }
    }
    else
    {
        rc = BAD_ARGS;
    }
    free(res_arr);
    clean_matrix(&test);
    return rc;
}