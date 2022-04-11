#include <stdio.h>

#define STABLE_WORK 0
#define INPUT_ERROR 1
#define MATRIX_INPUT_ERROR 2
#define INCORRECT_INPUT 3


void checker(int (*matrix)[10], int *row, int *col, int *result)
{
	if (*row == 1)
	{
		for (int i = 0; i < *col; i++)
			result[i] = 0;
		return;
	}
	for (int j = 0; j < *col; j++)
	{
		result[j] = 1;
		for (int i = 1; i < *row; i++)
			if (matrix[i][j] * matrix[i - 1][j] >= 0)
				result[j] = 0;
	}
}

int input_checker(int *col, int *row)
{
	if (scanf("%d%d", row, col) != 2)
		return INPUT_ERROR;
	if ((*row <= 0) || (*row > 10) || (*col <= 0) || (*col > 10))
		return INCORRECT_INPUT;
	return STABLE_WORK;
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
	int matrix[10][10];
	if (matrix_input(matrix, &column, &row))
		return INPUT_ERROR;
	int result[10];
	checker(matrix, &row, &column, result);
	for (int i = 0; i < column; i++)
		printf("%d ", result[i]);
}