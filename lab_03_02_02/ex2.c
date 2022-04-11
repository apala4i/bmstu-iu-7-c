#include <stdio.h>
#include <stdlib.h>

#define STABLE_WORK 0
#define INPUT_ERROR 1
#define MATRIX_INPUT_ERROR 2
#define INCORRECT_INPUT 3


int odd_checker(int cur_element)
{
    int sum = 0;
    while (cur_element > 0)
    {
        sum += cur_element % 10;
        cur_element /= 10;
    }
    return sum % 2;
}

void matrix_shift(int (*matrix)[10], int *row, int *col, int *stop)
{
    for (int i = *row + 1; i > *stop; i--)
        for (int j = 0; j < *col; j++)
            matrix[i][j] = matrix[i - 1][j];
    for (int i = 0; i < *col; i++)
        matrix[*stop][i] = -1;
    *row += 1;
}

int line_checker(int *array, int *col)
{
    int flag = 0;
    for (int i = 0; i < *col; i++)
    {
        flag += odd_checker(abs(array[i]));
        if (flag == 2)
            return 1;
    }
    return 0;
}

void matrix_editor(int (*matrix)[10], int *row, int *col)
{
    int i = 0;
    while (i < *row)
        if (line_checker(matrix[i], col))
        {
            matrix_shift(matrix, row, col, &i);
            i += 2;
        }
        else
            i += 1;
}

void matrix_printing(int (*matrix)[10], int *row, int *col)
{
    for (int i = 0; i < *row; i++)
    {
        for (int j = 0; j < *col; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int matrix_input(int (*matrix)[10], int *col, int *row)
{
    for (int i = 0; i < *row; i++)
        for (int j = 0; j < *col; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
                return MATRIX_INPUT_ERROR;
        }
    return STABLE_WORK;
}

int input_checker(int *col, int *row)
{
    if (scanf("%d%d", row, col) != 2)
        return INPUT_ERROR;
    if ((*row <= 0) || (*row > 10) || (*col <= 0) || (*col > 10))
        return INCORRECT_INPUT;
    return STABLE_WORK;
}

int main(void)
{
    int column, row;
    switch (input_checker(&column, &row))
    {
        case 1:
            return INPUT_ERROR;
        case 3:
            return INCORRECT_INPUT;
    }

    int matrix[20][10];

    if (matrix_input(matrix, &column, &row))
        return INPUT_ERROR;
    matrix_editor(matrix, &row, &column);
    matrix_printing(matrix, &row, &column);
    return STABLE_WORK;
}