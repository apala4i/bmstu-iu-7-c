#include <stdio.h>
#include <inttypes.h>
#include <sys/time.h>
#include <stdlib.h>

#define STABLE_WORK 0
#define INPUT_ERROR 1
#define ARRAY_SIZE_ERROR 2
#define NO_POSITIVE_OR_NEGATIVE_ERROR 4

int pos_checker(int *begin, int *end)
{
    while (begin != end)
    {
        if (*begin > 0)
            return STABLE_WORK;
        begin += 1;
    }
    return NO_POSITIVE_OR_NEGATIVE_ERROR;
}

int neg_checker(int *begin, int *end)
{
    while (begin != end)
    {
        if (*begin < 0)
            return 0;
        begin += 1;
    }
    return NO_POSITIVE_OR_NEGATIVE_ERROR;
}

int array_input(int *begin, int *end)
{
    while (begin != end)
    {
        *begin = rand() % 151 - 50;
        begin += 1;
    }
    return STABLE_WORK;
}


void process_1(int *array, int n, int *multiply)
{
	*multiply = 0;
	int begin = 0;
    int end = n;
    while ((begin <= n) && (end >= 0))
    {
        while ((array[begin] >= 0) && (begin < n))
            begin++;
        while ((array[end] <= 0) && (end > 0))
            end--;
        if ((array[begin] < 0) && (array[end] > 0))
            *multiply += array[begin] * array[end];
        begin++;
        end--;
    }
}


void process_2(int *array, int n, int *multiply)
{
	int begin = 0;
    int end = n;

	*multiply = 0;
    while ((begin <= n) && (end >= 0))
    {
        while ((*(array + begin) >= 0) && (begin < n))
            begin++;
        while ((*(array + end) <= 0) && (end > 0))
            end--;
        if ((*(array + begin) < 0) && (*(array + end) > 0))
            *multiply += *(array + begin) * (*(array + end));
        begin++;
        end--;
    }
}


void multiply_counter(int *begin, int *end, int *multiply)
{
    int *fixed_begin = begin;
    int *fixed_end = end;
	
	*multiply = 0;
    while ((begin <= fixed_end) && (end >= fixed_begin))
    {
        while ((*begin >= 0) && (begin < fixed_end))
            begin++;
        while ((*end <= 0) && (end > fixed_begin))
            end--;
        if ((*begin < 0) && (*end > 0))
            *multiply += (*begin) * (*end);
        begin++;
        end--;
    }
}


int main(void)
{
    int n;
    if (scanf("%d", &n) != 1)
    {
        printf("Input error.");
        return INPUT_ERROR;
    }
    int array[n];
    int *begin = array;
    int *end = array + n;
    if (array_input(begin, end))
    {
        printf("INPUT_ERROR");
        return INPUT_ERROR;
    }
    if (neg_checker(begin, end) || pos_checker(begin, end))
    {
        printf("NO_POSITIVE_OR_NEGATIVE_ERROR");
        return NO_POSITIVE_OR_NEGATIVE_ERROR;
    }
    int multiply = 0;
	int repeat_count;
	printf("Введите кол-во повторов\n");
	scanf("%d", &repeat_count);
	
	
	struct timeval tv_start, tv_stop;
	int64_t elapsed_time  = 0;
	for (int i = 0; i < repeat_count; i++)
	{
		gettimeofday(&tv_start, NULL);
		multiply_counter(begin, end - 1, &multiply);
		gettimeofday(&tv_stop, NULL);
		elapsed_time += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
		(tv_stop.tv_usec - tv_start.tv_usec);
	}
	elapsed_time /= repeat_count;
	printf("%" PRId64 " us\n", elapsed_time);

	elapsed_time = 0;
	for (int i = 0; i < repeat_count; i++)
	{
		gettimeofday(&tv_start, NULL);
		process_1(array, n - 1, &multiply);
		gettimeofday(&tv_stop, NULL);
		elapsed_time += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
		(tv_stop.tv_usec - tv_start.tv_usec);
	}
	elapsed_time /= repeat_count;
	printf("%" PRId64 " us\n", elapsed_time);
	
	elapsed_time = 0;
	for (int i = 0; i < repeat_count; i++)
	{
		gettimeofday(&tv_start, NULL);
		process_2(array, n - 1, &multiply);
		gettimeofday(&tv_stop, NULL);
		elapsed_time += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
		(tv_stop.tv_usec - tv_start.tv_usec);
	}
	elapsed_time /= repeat_count;
	printf("%" PRId64 " us\n", elapsed_time);

    return STABLE_WORK;
}