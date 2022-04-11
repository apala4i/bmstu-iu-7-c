#ifndef MYSORT_H
#define MYSORT_H

#include "defines.h"
#include <stdlib.h>

#define EMPTY_SEQUENCE 3
#define NULL_ERROR 4
#define MEMORY_ERROR 5

void swap(void *first, void *second, size_t size);
void *next(void *value, size_t size);
void *prev(void *value, size_t size);
int mysort(void *first, int number, size_t size, int (*comparator)(const void *, const void *));
int comp_for_int(const void *first, const void *second);
int comp_for_char(const void *first, const void *second);
int comp_for_float(const void *first, const void *second);

#endif