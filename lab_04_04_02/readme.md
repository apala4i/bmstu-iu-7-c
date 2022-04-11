# Тесты для лабораторной работы №04_04_02

## Входные данные
Строка размером не более 256 символов.

## Выходные данные
Слово YES или NO

## Позитивные тесты:
Тесты, при которых выводится NO:
- 01 - неверный день;
- 02 - неверно написан месяц;
- 03 - неверный год;
- 04 - нулевой год;
- 05 - строка из пробелов;
- 06 - в строке до корректной даты есть еще слова 
- 07 - в строке после корректной даты есть еще слова
- 08 - в строке одно слово
- 09 - в строке два слова
- 10 - в строке 3 невалидных слова
- 11 - исключение на невисокосный год кратный 100
- 12 - верный формат, но неверная дата(день)
- 13 - верный формат, но неверная дата(месяц)
- 14 - 31 число у апреля
- 15 - 31 число у июня
- 16 - 31 число у сентября
- 17 - 31 число у ноября
- 18 - слитное написание верной даты


Тесты, при которых выводится YES
- 19 - разный регистр у месяца
- 20 - месяц в верхнем регистре
- 21 - високосный год кратный 400
- 22 - високосный год кратный 4, но не кратный 100
- 23 - день записан с нулями до
- 24 - год записан с нулями до
- 25 - и день, и год записаны с нулями до
- 26 - 31 число у января
- 27 - 31 число у марта
- 28 - 31 число у мая
- 29 - 31 число у июля
- 30 - 31 число у августа
- 31 - 31 число у октября
- 32 - 31 число у декабря

## Негативные тесты:

- 01 - длина строки превышает 256 символов;
- 02 - пустая строка(ошибка fgets).