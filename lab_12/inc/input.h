#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include "defines.h"
#include "stdio.h"
#include "stdlib.h"

int digits_counter(const char *file_name, int *count);

int make_and_fill(const char *file_name, const int count, int **arr_begin, int **arr_end);

#endif