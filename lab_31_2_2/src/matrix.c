#include "matrix.h"
#include "errors.h"
#include <stdlib.h>

static int digit_sum(int digit)
{
    int res = 0;
    while (digit != 0)
    {
        res += digit % 10;
        digit /= 10;
    }
    return res;
}

void clean_matrix(matrix *src)
{
    free(src->elements);
    free(src->rows);
    src->elements = NULL;
    src->rows = NULL;
    src->columns_count = 0;
    src->rows_count = 0;
}

void matrix_init(matrix *src)
{
    src->rows = NULL;
    src->elements = NULL;
    src->columns_count = 0;
    src->rows_count = 0;
}

int read_matrix(FILE *flow, matrix *src)
{
    int rc = 0;
    if (flow == NULL)
    {
        rc = BAD_ARGS;
    }
    else
    {
        int rows, columns;
        if (fscanf(flow,"%d%d", &rows, &columns) != 2 || rows < 1 || columns < 1)
        {
            rc = INPUT_ERROR;
        }
        else
        {
            src->rows = malloc(sizeof (int *) * rows);
            if (src->rows == NULL)
            {
                rc = MEM_ERROR;
            }
            else
            {
                src->elements = malloc(sizeof (int) * columns * rows);
                if (src->rows == NULL)
                {
                    rc = MEM_ERROR;
                }
                else
                {
                    src->columns_count = columns;
                    src->rows_count = rows;
                    for (int i = 0; i < rows; ++i)
                    {
                        src->rows[i] = &(src->elements[i*columns]);
                    }
                    int cur_el;
                    for (int i = 0; i < rows; ++i)
                    {
                        if (!rc)
                        {
                            for (int j = 0; j < columns; ++j)
                            {
                                if (!rc)
                                {
                                    if (fscanf(flow,"%d", &cur_el) != 1)
                                    {
                                        rc = INPUT_ERROR;
                                    }
                                    else
                                    {
                                        src->rows[i][j] = cur_el;
                                    }
                                }
                            }
                        }
                    }

                }
            }
        }
    }
    if (rc)
    {
        clean_matrix(src);
    }
    return rc;
}

void print_matrix(FILE *flow, matrix *src)
{
    int col = src->columns_count;
    int row = src->rows_count;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            fprintf(flow,"%d ", (src->rows[i])[j]);
        }
        fprintf(flow, "\n");
    }
}

int matrix_process_count(matrix *src)
{
    int res = 0;
    for (int i = 0; i < src->rows_count; ++i)
    {
        for (int j = 0; j < src->columns_count; ++j)
        {
            if (digit_sum(src->rows[i][j]) > 10)
            {
                res += 1;
            }
        }
    }
    return res;
}

void matrix_process_fill(matrix *src, int *res_src)
{
    int cur_count = 0;
    for (int i = 0; i < src->rows_count; ++i)
    {
        for (int j = 0; j < src->columns_count; ++j)
        {
            if (digit_sum(src->rows[i][j]) > 10)
            {
                res_src[cur_count] = src->rows[i][j];
                cur_count++;
            }
        }
    }
}

void matrix_process_fill_back(matrix *src, const int *res_src)
{
    int cur_count = 0;
    for (int i = 0; i < src->rows_count; ++i)
    {
        for (int j = 0; j < src->columns_count; ++j)
        {
            if (digit_sum(src->rows[i][j]) > 10)
            {
                src->rows[i][j] = res_src[cur_count];
                cur_count++;
            }
        }
    }
}

