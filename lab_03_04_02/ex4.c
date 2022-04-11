#include <stdio.h>
#include <stdlib.h>

#define STABLE_WORK 0
#define INPUT_ERROR 1
#define SIZE_ERROR 2
#define MATRIX_INPUT_ERROR 3
#define VALUE_NOT_FOUND 4
#define NOT_SQUARE_MATRIX 5
#define N 10

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

int value_finder(int matrix[][N], const int row, const int column, int *max_value)
{
	*max_value = 0;
	for (int i = 1; i < row; i++)
		for (int j = 0; j < i; j++)
			if ((abs(matrix[i][column - j]) % 10 == 5) && ((*max_value < matrix[i][column - j]) || (*max_value == 0)))
				*max_value = matrix[i][column - j];
				
			
	if (!(*max_value))
	{
		printf("VALUE_NOT_FOUND");
		return VALUE_NOT_FOUND;
	}
	return STABLE_WORK;
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
	if ((row != column) || (row == 1))
	{
		printf("NOT_SQUARE_MATRIX");
		return NOT_SQUARE_MATRIX;
	}
	int matrix[10][10];
	if (matrix_input(matrix, row, column))
		return MATRIX_INPUT_ERROR;
	
	int max_value;
	if (value_finder(matrix, row, column - 1, &max_value))
	{
		return VALUE_NOT_FOUND;
	}
	printf("valiue: %d", max_value);
	
	return STABLE_WORK;
}