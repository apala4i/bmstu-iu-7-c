#include <stdio.h>
#include <math.h>

int main(void)
{
	// Координаты точек.
	float ax, ay, bx, by, cx, cy;
	// Длины сторон треугольника.
	float first_side, second_side, third_side, perimeter;
	
	// Чтение координат точек.
	scanf("%f%f%f%f%f%f", &ax, &ay, &bx, &by, &cx, &cy);
	
	// Расчёт сторон треугольника.
	first_side = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
	second_side = sqrt((bx - cx) * (bx - cx) + (by - cy) * (by - cy));
	third_side = sqrt((cx - ax) * (cx - ax) + (cy - ay) * (cy - ay));
	
	// Расчёт периметра.
	perimeter = first_side + second_side + third_side;
	
	// Вывод значений.
	printf("%.6f", perimeter);

	return 0;
}