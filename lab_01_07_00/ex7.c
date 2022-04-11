#include <stdio.h>
#include <math.h>

#define INPUT_ERROR 1
#define EPS_OUT_OF_RANGE 2

// Объявление функций.
void s(double, double *, double);
void f(double, double *);

int main(void)
{
	// Объявление переменных.
	double x, eps, augment, delta;
	double fx = 0., sx = 0.;
	
	// Считывание переменных с проверкой на валидность.
	if (scanf("%lf%lf", &x, &eps) != 2)
	{
		printf("Input error");
		return INPUT_ERROR;
	}
	if (eps <= 0.0 || eps > 1)
	{
		printf("Epsilon must be in range 0 < eps <= 1");
		return EPS_OUT_OF_RANGE;
	}
	
	// Нахождение точного значения.
	f(x, &fx);
	
	// Нахождение приближённого значения.
	s(x, &sx, eps);
	
	// Нахождение абсолютной погрешности.
	augment = fabs(fx - sx);
	
	// Нахождение относительной погрешности.
	delta = augment / fabs(fx);	
	
	// Вывод результатов.
	printf("%.6lf %.6lf %.6lf %.6lf", sx, fx, augment, delta);	
}

// Функция для нахождения приближённого значения.
void s(double x, double *sx, double eps)
{
	// Объявление локальных переменных.
	double n, current;
	
	// Вычисление приближённого значения.
	current = 1;
	n = 0.;
	while (fabs(current) > eps)
	{
		n++;
		*sx += current;
		current *= x / n;
	}
}

// Функция для нахождения абсолютного значения.
void f(double x, double *fx)
{
	// Нет возврата, так как в качестве аргумента был передан указатель.
	*fx = exp(x);
}