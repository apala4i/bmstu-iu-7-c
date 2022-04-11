#include <stdio.h>

#define STABLE_WORK 0
#define INPUT_ERROR 1
#define ARRAY_SIZE_ERROR 3

void local_counter(int *arr, int *n, int *count)
{
	for (int i = 1; i < *n - 1; i++)
		if ((arr[i] < arr[i - 1]) && (arr[i] < arr[i + 1]))
			*count += 1;
			
}

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

    return STABLE_WORK;
}

int main(void)
{
	setbuf(stdout, NULL);
	int n;
	int array[10];
	
	printf("Input count of array elements: ");
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
	
	if (array_input(array, n))
		return INPUT_ERROR;
	
	int count = 0;
	local_counter(array, &n, &count);
	printf("There are %d local minimums", count);
	return STABLE_WORK;
}