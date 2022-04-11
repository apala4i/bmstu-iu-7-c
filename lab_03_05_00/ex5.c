#include <stdio.h>

#define STABLE_WORK 0
#define INPUT_ERROR 1
#define SIZE_ERROR 2
#define MATRIX_INPUT_ERROR 3
#define NO_PRIME_NUMBERS 4
#define N 10
#define PRIME 1
#define NOT_PRIME 0

void matrix_print(int matrix[][N], const int row, const int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}

void swap(int *first, int *second)
{
	int temp;
	temp = *first;
	*first = *second;
	*second = temp;
}

void array_reverse(int *array, const int count)
{
	for (int i = 0; i < (count / 2); i++)
		swap(&array[i], &array[count - 1 - i]);		
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

int prime_checker(int num)
{
	if (num < 2)
		return NOT_PRIME;
	for (int i = 2; i * i <= num; i++)
		if (!(num % i))
			return NOT_PRIME;
	return PRIME;
}

int prime_filler(int matrix[][N], const int row, const int column, int *prime_count, int *prime_numbers)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			if (prime_checker(matrix[i][j]))
			{
				prime_numbers[*prime_count] = matrix[i][j];
				(*prime_count)++;
			}
	}
	if (!(*prime_count))
	{
		printf("NO_PRIME_NUMBERS");
		return NO_PRIME_NUMBERS;
	}
	return STABLE_WORK;
}

void prime_insert(int matrix[][N], const int row, const int column, int *prime_numbers)
{
	int current_count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			if (prime_checker(matrix[i][j]))
			{
				matrix[i][j] = prime_numbers[current_count];
				current_count++;
			}
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
	int prime_numbers[100];
	int prime_count = 0;
	if (prime_filler(matrix, row, column, &prime_count, prime_numbers))
		return NO_PRIME_NUMBERS;
	array_reverse(prime_numbers, prime_count);
	prime_insert(matrix, row, column, prime_numbers);
	matrix_print(matrix, row, column);
	return STABLE_WORK;
}