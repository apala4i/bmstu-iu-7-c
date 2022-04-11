#include "func.h"

int max_finder(FILE *file_name, double *max)
{
    double current_max;
    if (fscanf(file_name, "%lf", &current_max) != 1)
        return INPUT_ERROR;
    *max = current_max;
    while (fscanf(file_name, "%lf", &current_max) == 1)
    {
        if (current_max > *max)
            *max = current_max;
    }
    fseek(file_name, 0, SEEK_SET);
    return STABLE_WORK;
}

int min_finder(FILE *file_name, double *min)
{
    double current_min;
    if (fscanf(file_name, "%lf", &current_min) != 1)
        return INPUT_ERROR;
    *min = current_min;
    while (fscanf(file_name, "%lf", &current_min) == 1)
    {
        if (current_min < *min)
            *min = current_min;
    }
    fseek(file_name, 0, SEEK_SET);
    return STABLE_WORK;
}

int average_check(FILE *file_name, int *count, const double average)
{
    int digit_count = 0;
    double current_digit;
    while (fscanf(file_name, "%lf", &current_digit) == 1)
    {
        if (current_digit > average)
            (*count)++;
        digit_count++;
    }
    return digit_count;
}