#include "../inc/matrix.h"
#include "../inc/error.h"
#include <stdlib.h>
#include <math.h>

#define EPS 0.0000001

void ma_init_matrix(matrix *src)
{
    src->columns = 0;
    src->rows = 0;
    src->elements = NULL;
}

void ma_clear(matrix *src)
{
    src->columns = 0;
    src->rows = 0;
    free(src->elements);
    src->elements = NULL;
}

double *ma_get_value(const matrix *src, int row, int col)
{
    return &(((double **)src->elements)[row])[col];
}

void ma_set_value(const matrix *src, int row, int col, const double new_val)
{
    (((double **)src->elements)[row])[col] = new_val;
}

void ma_usual_print_matrix(const matrix *src, FILE *flow)
{
    int rows = src->rows, columns = src->columns;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            fprintf(flow, "%.6lf ", *ma_get_value(src, i, j));
        }
        fprintf(flow, "\n");
    }
}

int ma_not_zero_count(const matrix *src)
{
    int rows = src->rows;
    int columns = src->columns;
    int res = 0;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            if (fabs(*ma_get_value(src, i, j) - 0.0) >= EPS)
            {
                ++res;
            }
        }
    }
    return res;
}

void ma_coordinate_print_matrix(const matrix *src, FILE *flow)
{
    int rows = src->rows, columns = src->columns;
    int not_zero = ma_not_zero_count(src);
    fprintf(flow, "%d %d %d", rows, columns, not_zero);

    if (not_zero == 0)
    {
        return;
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            if (fabs(*ma_get_value(src, i, j) - 0.0) >= EPS)
            {
                fprintf(flow, "\n%d %d %.6lf", i + 1, j + 1, *ma_get_value(src, i, j));
            }
        }
    }
}

void ma_zero_fill(const matrix *src)
{
    int rows = src->rows, columns = src->columns;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            ma_set_value(src, i, j, 0.0);
        }
    }
}

int ma_create_matrix(matrix *src, int rows, int columns)
{
    // create memory for elements
    src->elements = (double **)malloc(rows * sizeof (double *) + columns * rows * sizeof (double));
    if (src->elements == NULL)
    {
        return MEM_ERROR;
    }

    src->columns = columns;
    src->rows = rows;


    // fill pointers to rows
    for (int i = 0; i < rows; ++i)
    {
        ((double **)src->elements)[i] = ((double *)((char *)src->elements + rows * sizeof (double *))) + i * columns;
    }
    return EXIT_SUCCESS;
}

int ma_read_matrix(FILE *flow, matrix *dst)
{
    if (flow == NULL)
    {
        return FILE_ERROR;
    }

    // read dim and count of not zero elements
    int rows, columns, elements_count;
    if (fscanf(flow, "%d %d %d", &rows, &columns, &elements_count) != 3
        || rows < 1 || columns < 1 || elements_count < 0)
    {
        return INPUT_ERROR;
    }

    if (ma_create_matrix(dst, rows, columns))
    {
        return MEM_ERROR;
    }

    if (elements_count != rows * columns)
    {
        ma_zero_fill(dst);
    }

    // fill elements
    int cur_row, cur_col;
    double cur_value;
    for (int i = 0; i < elements_count; ++i)
    {
        if (fscanf(flow, "%d %d %lf", &cur_row, &cur_col, &cur_value) != 3 || cur_row < 1 || cur_row > rows
            || cur_col < 1 || cur_col > columns)
        {
            ma_clear(dst);
            return INPUT_ERROR;
        }
        ma_set_value(dst, cur_row - 1, cur_col - 1, cur_value);
    }

    return EXIT_SUCCESS;
}

int ma_matrix_sum(matrix *dst, const matrix *first, const matrix *second)
{
    if (first->columns != second->columns || first->rows != second->rows)
    {
        return DIMENSION_ERROR;
    }

    int rows = first->rows;
    int columns = first->columns;

    if (ma_create_matrix(dst, rows, columns))
    {
        return MATRIX_CREATE_ERROR;
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            ma_set_value(dst, i, j, *ma_get_value(first, i, j) + *ma_get_value(second, i, j));
        }
    }
    return EXIT_SUCCESS;
}

int ma_matrix_mul(matrix *dst, const matrix *first, const matrix *second)
{
    if (first->columns != second->rows)
    {
        return DIMENSION_ERROR;
    }

    int rows = first->rows;
    int columns = second->columns;

    if (ma_create_matrix(dst, rows, columns))
    {
        return MATRIX_CREATE_ERROR;
    }

    int element_in_row_column = first->columns;
    double cur_res;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            cur_res = 0.0;
            for (int k = 0; k < element_in_row_column; ++k)
            {
                cur_res += *ma_get_value(first, i, k) * *ma_get_value(second, k, j);
            }
            ma_set_value(dst, i, j, cur_res);
        }
    }
    return EXIT_SUCCESS;
}

void rows_addition(matrix *src, const int first, const int second, const int start)
{
    if (fabs(*ma_get_value(src, second, start) - 0.0) <= EPS)
    {
        return;
    }
    double coefficient = *ma_get_value(src, second, start) / *ma_get_value(src, first, start);
    int columns = src->columns;
    for (int i = start; i < columns; ++i)
    {
        *ma_get_value(src, second, i) -= coefficient * *ma_get_value(src, first, i);
    }
}

void ma_swap_rows(matrix *src, const int first, const int second)
{
    double *tmp;
    tmp = ((double **)src->elements)[first];
    ((double **)src->elements)[first] = ((double **)src->elements)[second];
    ((double **)src->elements)[second] = tmp;
}

int ma_non_zero_swap(matrix *src, const int start, bool *change_sign)
{
    int rows = src->rows;
    bool flag;
    flag = false;
    if ((*ma_get_value(src, start, start) - 0.0) > EPS)
    {
        return EXIT_SUCCESS;
    }
    for (int j = start + 1; j < rows; ++j)
    {
        if (!flag && (*ma_get_value(src, j, start) - 0.0) > EPS)
        {
            ma_swap_rows(src, start, j);
            flag = true;
            *change_sign = !(*change_sign);
        }
    }
    if (flag == false)
    {
        return ZERO_DET;
    }

    return EXIT_SUCCESS;
}


int ma_gauss_determinant_finder(matrix *src, double *det_value)
{
    if (src->columns != src->rows)
    {
        return NOT_SQUARE_MATRIX;
    }

    int rows_columns = src->rows;
    bool change_sign = false;

    for (int i = 0; i < rows_columns - 1; ++i)
    {
        if (ma_non_zero_swap(src, i, &change_sign))
        {
            *det_value = 0.0;
            return EXIT_SUCCESS;
        }
        for (int j = i + 1; j < rows_columns; ++j)
        {
            rows_addition(src, i, j, i);
        }
    }


    *det_value = 1.0;
    for (int i = 0; i < rows_columns; ++i)
    {
        *det_value *= *ma_get_value(src, i, i);
    }

    if (change_sign)
    {
        *(det_value) *= -1.0;
    }

    return EXIT_SUCCESS;
}