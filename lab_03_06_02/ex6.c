#include <stdio.h>

#define STABLE_WORK 0
#define INPUT_ERROR 1
#define SIZE_ERROR 2
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

void column_filler(int *matrix, const int row, int *motion, int *current_digit)
{
	if ((*motion) %= 2)
		for (int i = 0; i < row; i++)
			*(matrix + i * N) = (*current_digit)++;
	else
		for (int i = row - 1; i >= 0; i--)
			*(matrix + i * N) = (*current_digit)++;
	(*motion)++;
}

void bull_move(int matrix[][N], const int row, const int column)
{
	int motion = column % 2;
	int current_digit = 1;
	for (int i = column - 1; i >= 0; i--)
		column_filler(&(matrix[0][i]), row, &motion, &current_digit);
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
	bull_move(matrix, row, column);
	matrix_print(matrix, row, column);
	return STABLE_WORK;
}