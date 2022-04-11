// app.exe action mtr_1.txt [mtr_2.txt] res.txt
// a - сложение
// m - умножение
// o - Вычисление определителя методом Гаусса

// пример хранения матрицы в файле
// 2 2 3 (первая строка) 2 - кол-во строк 2 - кол-во столбцов 3 - кол-во ненулевых элементов
// 1 1 1 (вторая строка) первая строка первый столбец значение 1
// 1 2 2 (третья строка) первая строка второй столбец значение 2
// 2 1 3 (четвертая строка) вторая строка первый столбец значение 3

// выделение памяти для матрицы - матрица хранится единым блоком построчно. В памяти размещается, помимо данных,
// массив указателей на строки.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/error.h"
#include "../inc/matrix.h"

#define SUM_ACTION 9
#define MUL_ACTION 10
#define DET_ACTION 11

int action_finder(const char *action, const int argc)
{
    if (strcmp(action, "a") == 0)
    {
        if (argc != 5)
        {
            return ARG_ERROR;
        }
        return SUM_ACTION;
    }
    if (strcmp(action, "m") == 0)
    {
        if (argc != 5)
        {
            return ARG_ERROR;
        }
        return MUL_ACTION;
    }
    if (strcmp(action, "o") == 0)
    {
        if (argc != 4)
        {
            return ARG_ERROR;
        }
        return DET_ACTION;
    }
    return ARG_ERROR;
}

int main(int argc, char *argv[])
{
    if (argc > 5 || argc < 4)
    {
        return ARG_ERROR;
    }

    int action = action_finder(argv[1], argc);

    if (action == ARG_ERROR)
    {
        return ARG_ERROR;
    }

    if (action == SUM_ACTION || action == MUL_ACTION)
    {
        //read first matrix
        FILE *input_file = fopen(argv[2], "r");
        if (input_file == NULL)
        {
            return FILE_ERROR;
        }

        matrix first_matrix;
        ma_init_matrix(&first_matrix);
        int rc = ma_read_matrix(input_file, &first_matrix);
        fclose(input_file);
        if (rc)
        {
            return rc;
        }

        input_file = fopen(argv[3], "r");

        if (input_file == NULL)
        {
            ma_clear(&first_matrix);
            return FILE_ERROR;
        }

        matrix second_matrix;
        ma_init_matrix(&second_matrix);
        rc = ma_read_matrix(input_file, &second_matrix);
        fclose(input_file);
        if (rc)
        {
            ma_clear(&first_matrix);
            return rc;
        }

        matrix res_matrix;
        ma_init_matrix(&res_matrix);

        if (action == SUM_ACTION)
        {
            rc = ma_matrix_sum(&res_matrix, &first_matrix, &second_matrix);
            if (rc)
            {
                ma_clear(&first_matrix);
                ma_clear(&second_matrix);
                return rc;
            }
        }
        else
        {
            rc = ma_matrix_mul(&res_matrix, &first_matrix, &second_matrix);
            if (rc)
            {
                ma_clear(&first_matrix);
                ma_clear(&second_matrix);
                return rc;
            }
        }

        FILE *output_file = fopen(argv[4], "w");
        if (output_file == NULL)
        {
            ma_clear(&first_matrix);
            ma_clear(&second_matrix);
            ma_clear(&res_matrix);
            return FILE_ERROR;
        }

        ma_coordinate_print_matrix(&res_matrix, output_file);

        fclose(output_file);
        ma_clear(&first_matrix);
        ma_clear(&second_matrix);
        ma_clear(&res_matrix);
    }

    if (action == DET_ACTION)
    {
        //read matrix
        FILE *input_file = fopen(argv[2], "r");
        if (input_file == NULL)
        {
            return FILE_ERROR;
        }

        matrix det_matrix;
        ma_init_matrix(&det_matrix);
        int rc = ma_read_matrix(input_file, &det_matrix);
        fclose(input_file);
        if (rc)
        {
            return rc;
        }

        double det;

        rc = ma_gauss_determinant_finder(&det_matrix, &det);
        if (rc)
        {
            ma_clear(&det_matrix);
            return rc;
        }
        ma_clear(&det_matrix);

        FILE *output_file = fopen(argv[3], "w");
        if (output_file == NULL)
        {
            return FILE_ERROR;
        }

        fprintf(output_file, "%.6lf", det);
    }

    return EXIT_SUCCESS;
}