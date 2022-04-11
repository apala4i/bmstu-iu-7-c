#ifndef FUNCS_C
#define FUNCS_C
#define _GNU_SOURCE
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
#define MEM_ERROR 7
#define BAD_ARGS 8

struct objects
{
    char *name;
    double mass;
    double volume;
    double density;
};

int structures_init(struct objects *values, const int count);

int structures_clean(struct objects *values, const int count);

int count_structures(int *count, FILE *input_file);

int read_structures(struct objects *values, FILE *input_file);

void print_structures(struct objects *values, const int count);

void needle_values(const struct objects *values, const int count, const char *needle);

void bubble_sort_density(struct objects *values, const int count);

#endif