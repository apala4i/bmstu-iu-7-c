#include <stdio.h>
#include <math.h>

// Определение ошибок.
#define INPUT_ERROR 1
#define NONEXISTING_TRIANGLE 2

// Определение функций.
double vector_coordinates_x(double, double);
double vector_coordinates_y(double, double);
double vector_product(double, double, double, double);

int main(void)
{
	// Определение необходимых переменных.
	int checker;
	double ax, ay, bx, by, cx, cy;
	double abx, aby, acx, acy, bcx, bcy, cbx, cby;
	double product1, product2, product3;
	double len_ab, len_ac, len_bc;
	
	// Считывание координат с проверкой на валидность.
	checker = scanf("%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy);
	if (checker != 6)
	{
		printf("Invalid input");
		return INPUT_ERROR;
	}
	
	// Расчёт длин треугольника, для проверка на его существования.
	len_ab = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
	len_ac = sqrt((ax - cx) * (ax - cx) + (ay - cy) * (ay - cy));
	len_bc = sqrt((bx - cx) * (bx - cx) + (by - cy) * (by - cy));
	
	// Проверка на существование треугольника.
	if ((len_ab + len_bc <= len_ac) || (len_ac + len_bc <= len_ab) ||
		(len_ab + len_ac <= len_bc))
	{
		printf("a, b, c is on one line");
		return NONEXISTING_TRIANGLE;
	}
	
	// Расчёт координат векторов.
	acx = vector_coordinates_x(ax, cx);
	acy = vector_coordinates_x(ay, cy);
	abx = vector_coordinates_x(ax, bx);
	aby = vector_coordinates_x(ay, by);
	bcx = vector_coordinates_x(bx, cx);
	bcy = vector_coordinates_y(by, cy);
	cbx = vector_coordinates_x(cx, bx);
	cby = vector_coordinates_x(cy, by);
	
	// Расчёт векторных произведений.
	product1 = vector_product(abx, aby, acx, acy);
	product2 = vector_product(abx, aby, cbx, cby);
	product3 = vector_product(acx, acy, bcx, bcy);
	
	// Определение вида треугольника.
	if ((product1 * product2 * product3 >= 0.0) &&
		(product1 * product2 * product3 <= 0.0))
		printf("1");
	else if (product1 * product2 * product3 > 0.0)
		printf("0");
	else
		printf("2");
		
	return 0;
}

// Функция для поиска x координаты вектора
double vector_coordinates_x(double ax, double bx)
{
	// Обьявление локальной переменной.
	double vx;
	
	// Расчёт координаты вектора.
	vx = bx - ax;
	
	// Возвращение результата.
	return vx;
}

// Функция для поиска координаты y вектора.
double vector_coordinates_y(double ay, double by)
{
	// Обьявление локальной переменной.
	double vy;
	
	// Расчёт координаты вектора.
	vy = by - ay;
	
	// Возвращение результата.
	return vy;
}

// Функция для поиска векторного произведения.
double vector_product(double ax, double ay, double bx, double by)
{
	// Обьявление локальной переменной.
	double result;
	
	// Расчёт векторного произведения.
	result = ax * bx + ay * by;
	
	// Возвращение результата.
	return result;
}