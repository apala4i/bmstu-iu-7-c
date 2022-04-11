#include <stdio.h>

#define STABLE_WORK 0
#define SPECIAL_INPUT 100
#define EMPTY_ARRAY_ERROR 2
#define OVERFLOW_ARRAY 1

int array_input(int *arr, int *n)
{
	int checker;
	for (int i = 0; i < 200000; i++)
	{
		if (scanf("%d", &arr[i]) != 1)
		{
			if (*n == 0)
				return EMPTY_ARRAY_ERROR;
			return STABLE_WORK;
		}
		*n += 1;
	}
	if (scanf("%d", &checker) == 1)
		return OVERFLOW_ARRAY;
	return STABLE_WORK;
}

void print_array(int *array, int new_len)
{
	for (int i = 0; i < new_len; i++)
		printf("%d ", array[i]);
}

void bubble_sorting(int *array, int n)
{
	int helper;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (n - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				helper = array[j];
				array[j] = array[j + 1];
				array[j + 1] = helper;
			}
		}
	}
}

int main(void)
{
	int n = 0;
	int input_checker = 0;
	int array[200000];

	switch (array_input(array, &n))
	{
		case OVERFLOW_ARRAY:
			input_checker = OVERFLOW_ARRAY;
			break;
		case EMPTY_ARRAY_ERROR:
			printf("Empty array error.");
			return EMPTY_ARRAY_ERROR;
	}
	bubble_sorting(array, n);
	print_array(array, n);

	if (input_checker)
		return SPECIAL_INPUT;

	return STABLE_WORK;
}