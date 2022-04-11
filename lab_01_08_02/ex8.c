#include <stdio.h>
#include <stdint.h>

// Обьявление ошибок.
#define INVALID_INPUT 1
#define NEGATIVE_BYTES_COUNT 2

// Обьявление функции.
uint32_t byte_shifting(uint32_t, int);

int main(void)
{
	// Обьявление необходимых переменных.
	int bytes_count;
	uint32_t digit, result, size, current_byte, check;

	// Считывание необходимых значений с проверкой на валидность данных.
	check = scanf("%u%d", &digit, &bytes_count);
	if (check != 2)
	{
		printf("Error: Invalid input");
		return INVALID_INPUT;
	}
	if (bytes_count < 0)
	{
		printf("Error: this digit can't be negative");
		return NEGATIVE_BYTES_COUNT;
	}
	size = 32;
	
	// Выявления результата.
	result = byte_shifting(digit, bytes_count);
	
	// Вывод результата.
	printf("Result: ");
	for (int i = size - 1; i >= 0; i--)
	{
		current_byte = result >> i & 1;
		printf("%u", current_byte);
	}

	return 0;	
}

// Функция для осуществления побитового сдвига.
uint32_t byte_shifting(uint32_t digit, int bytes_count)
{
	uint32_t result = (digit << bytes_count) | (digit >> (32 - bytes_count));
	
	return result;
}