#include <stdio.h>
#include "func.h"
#define BAD_PARAM -1
#define NOT_ENOUGH_DIGITS -2

int main(int argc, char *argv[])
{
    if (argc != 2)
        return BAD_PARAM;
    FILE *file_name = fopen(argv[1], "r");
//    FILE *file_name = fopen("C:\\C_labs\\lab_05_02_01\\test.txt", "r");
    double max = 0, min = 0;
    double average;
    min_finder(file_name, &min);
    max_finder(file_name, &max);
    average = (max + min) / 2;
    int count = 0;
    if (average_check(file_name, &count, average) < 2)
        return NOT_ENOUGH_DIGITS;
    printf("%d", count);
}
