#include <stdio.h>

// Определение кодов ошибок.
#define INPUT_ERROR 2
#define DEGREE_ERROR 1

// Функция для возведения числа n в степень a.
long long power(long long, long long);

int main(void)
{
	// Обьявление необходимых переменных.
	int a, n, checker;
	long long result;

	// Считывание данных, с проверкой на валидность.
	checker = scanf("%d%d", &a, &n);

	// Проверка на валидность введённых данных, и на неотрицательность степени.
	if (checker != 2)
	{
		printf("not all data is entered");
		return INPUT_ERROR;
	}
	if (n <= 0)
	{
		printf("degree can't be less or equal to zero in this programm");
		return DEGREE_ERROR;
	}

	// Вычисление результата.
	result = power(n, a);

	// Вывод результата.
	printf("%lld", result);
	
	return 0;
}

long long power(long long n, long long a)
{
	// Инициализация переменной с результатом в локальной области видимости.
	long long result;
	result = a;
	
	// Проверка на нулевую степень.
	if (n == 0)
		result = 1;
	else
		// Расчёт степени через цикл for.
		for (int i = 1; i < n; i++)
			result *= a;
	// Возврат результата.
	return result;
}