#include <stdio.h>

#define STABLE_WORK 0
#define INPUT_ERROR 1
#define SIZE_ERROR 2
#define MATRIX_INPUT_ERROR 3
#define N 10

void matrix_print(int matrix[][N], const int row, const int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}

void swap(int *first, int *second, const int column)
{
	int temp;
	for (int i = 0; i < column; i++)
	{
		temp = first[i];
		first[i] = second[i];
		second[i] = temp;
	}
}

void bubble_sorting_strokes(int *array, const int n, int matrix[][N], const int column)
{
	int helper;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < (n - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				helper = array[j];
				array[j] = array[j + 1];
				array[j + 1] = helper;
				swap(matrix[j], matrix[j + 1], column);
			}
		}
	}
}

int matrix_input(int matrix[][N], const int row, const int column)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
		{
			if (scanf("%d", &(matrix[i][j])) != 1)
			{
				printf("MATRIX_INPUT_ERROR");
				return MATRIX_INPUT_ERROR;
			}
		}
	return STABLE_WORK;
}

void multiply_counter(const int *current_stroke, int *current_value, const int column)
{
	*current_value = 1;
	for (int i = 0; i < column; i++)
		*current_value *= current_stroke[i];
}

void stroke_multiply_filler(int *stroke_multiply, int matrix[][N], const int row, const int column)
{
	for (int i = 0; i < row; i++)
	{
		multiply_counter(matrix[i], &stroke_multiply[i], column);
	}
}

int main(void)
{
	int row, column;
	
	if (scanf("%d%d", &row, &column) != 2)
	{
		printf("INPUT_ERROR");
		return INPUT_ERROR;
	}
	if ((row > N) || (row < 1) || (column > N) || (column < 1))
	{
		printf("SIZE_ERROR");
		return SIZE_ERROR;
	}
	int matrix[10][10];
	if (matrix_input(matrix, row, column))
		return MATRIX_INPUT_ERROR;
	
	int stroke_multiply[10];

	stroke_multiply_filler(stroke_multiply, matrix, row, column);
	bubble_sorting_strokes(stroke_multiply, row, matrix, column);

	matrix_print(matrix, row, column);
	return STABLE_WORK;
}