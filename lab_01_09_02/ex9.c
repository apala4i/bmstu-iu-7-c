#include <stdio.h>
#include <math.h>

// Объявление ошибок.
#define INPUT_ERROR 1
#define EMPTY_SEQUENCE 2

// Объявление функции.
int mult(double *);

int main(void)
{
	double sum = 0.0;
	int error;
	
	error = mult(&sum);
	if (error == 2)
	{
		printf("Empty sequence error");
		return EMPTY_SEQUENCE;
	}
	else if (error == 1)
	{
		printf("Input error");
		return INPUT_ERROR;
	}
	
	// Вывод суммы.
	printf("%.6lf", sum);
	
	return 0;
}

int mult(double *sum)
{
	// Обьявление локальных переменных.
	int n = 0, checker;
	double curr;
	
	// Считывание первого элемента последовательности.
	checker = scanf("%lf", &curr);
	
	// Проверка на отрицательность.
	if (checker != 1)
	{
		return INPUT_ERROR;
	}
	if (curr < 0.0)
		return EMPTY_SEQUENCE;
	
	// Расчёт суммы.
	while (curr >= 0.0)
	{
		n += 1;
		*sum += sqrt(n + curr);
		// Считывание следующего элемента последовательности.
		if (scanf("%lf", &curr) != 1)
			return INPUT_ERROR;
	}
	*sum /= n;
	return 0;
}	