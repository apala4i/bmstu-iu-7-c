#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>

typedef struct
{
    int **rows;
    int *elements;
    int rows_count;
    int columns_count;
}matrix;

void clean_matrix(matrix *src);

void matrix_init(matrix *src);

int read_matrix(FILE *flow, matrix *src);

void print_matrix(FILE *flow, matrix *src);

int matrix_process_count(matrix *src);

void matrix_process_fill(matrix *src, int *res_src);

void matrix_process_fill_back(matrix *src, const int *res_src);

#endif