#include <stdio.h>
#include <math.h>

#define INPUT_ERROR 1
#define ARRAY_SIZE_ERROR 2
#define ARRAY_INPUT_ERROR 3
#define EMPTY_ARRAY_ERROR 4


int array_input(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (scanf("%d", &arr[i]) != 1)
		{
			printf("Input array error");
			return 1;
		}
	}
	return 0;
}

void print_array(int *array, int new_len)
{
	for (int i = 0; i < new_len; i++)
		printf("%d ", array[i]);
}

int root_finder(int *array, int *n)
{
	int check, count = 0, i = 0;
	double b;
	for (int try = 0; try < *n; try++)
	{
		b = sqrt(array[i]);
		check = b;
		if ((b - check >= 0) && (b - check <= 0))
		{
			count += 1;
			for (int j = i; j < (*n); j++)
				array[j] = array[j + 1];
		}
		else
			i += 1;
	}
	*n -= count;
	if (*n == 0)
		return 1;
	return 0;
}

int main(void)
{
	int n;
	if (scanf("%d", &n) != 1)
	{
		printf("Input error.");
		return INPUT_ERROR;
	}

	if ((n > 10) || (n <= 0))
	{
		printf("Array size error.");
		return ARRAY_SIZE_ERROR;
	}
	int array[10];

	if (array_input(array, n) == 1)
	{
		printf("Array input error.");
		return ARRAY_INPUT_ERROR;
	}

	if (root_finder(array, &n) == 1)
	{
		printf("Empty array error.");
		return EMPTY_ARRAY_ERROR;
	}
	print_array(array, n);
	return 0;
}