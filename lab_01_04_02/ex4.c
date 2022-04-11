#include <stdio.h>

int main(void)
{
	// Обьявление параметров.
	int hours, minutes, seconds;
	int lost_seconds;

	// Считывание секунд.
	scanf("%d", &seconds);
	
	// Расчёт часов, секунд, минут.
	hours = seconds / 3600;
	minutes = seconds % 3600 / 60;
	lost_seconds = seconds % 60;
	
	// Выврод результатов.
	printf("%d %d %d", hours, minutes, lost_seconds);

	return 0;
}