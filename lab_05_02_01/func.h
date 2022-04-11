#include <stdio.h>

#define INPUT_ERROR -2
#define STABLE_WORK 0

int max_finder(FILE *file_name, double *max);
int min_finder(FILE *file_name, double *min);
int average_check(FILE *file_name, int *count, const double average);