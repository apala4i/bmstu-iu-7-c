#ifndef FUNCS_C
#define FUNCS_C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 25
#define MAX_STRUCTURES 15

#define ARG_ERROR 1
#define FILE_DOES_NOT_EXIST 2
#define EMPTY_FILE 3
#define INPUT_ERROR 4
#define NAME_SIZE_ERROR 5
#define STRUCTURES_SIZE_ERROR 6

struct objects
{
    char name[26];
    double mass;
    double volume;
    double density;
};

int read_structures(struct objects *values, int *count, FILE *input_file);

void print_structures(struct objects *values, const int count);

void needle_values(const struct objects *values, const int count, const char *needle);

void bubble_sort_density(struct objects *values, const int count);

#endif