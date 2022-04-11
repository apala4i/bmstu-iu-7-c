#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int rows;
    int columns;
    double **elements;
}matrix;

void ma_init_matrix(matrix *src);

void ma_clear(matrix *src);

double *ma_get_value(const matrix *src, int row, int col);

void ma_set_value(const matrix *src, int row, int col, const double new_val);

int ma_read_matrix(FILE *flow, matrix *dst);

void ma_zero_fill(const matrix *src);

int ma_create_matrix(matrix *src, int rows, int columns);

void ma_usual_print_matrix(const matrix *src, FILE *flow);

void ma_coordinate_print_matrix(const matrix *src, FILE *flow);

int ma_matrix_sum(matrix *dst, const matrix *first, const matrix *second);

int ma_matrix_mul(matrix *dst, const matrix *first, const matrix *second);

int ma_gauss_determinant_finder(matrix *src, double *res);

void ma_swap_rows(matrix *src, const int first, const int second);

int ma_non_zero_swap(matrix *src, const int start, bool *change_sign);

#endif