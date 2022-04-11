#include <stdio.h>

#define NUM 13

// Счётчик суммы цифр в числе.
int digits_sum(int value)
{
	int sum = 0;
	while (value > 0)
	{
		sum += value % 10;
		value /= 10;
	}
	return sum;
}

// Подсчёт подходящих билетов.
void lucky_counter(int *count)
{
	for (int i = 100; i < 1000; i ++)
		if (digits_sum(i) == NUM)
			*count += 1;
			
}

int main(void)
{
	int count = 0;
	lucky_counter(&count);
	printf("There are %d such tickets", count);
}