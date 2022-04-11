#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define STABLE_WORK 0
#define EMPTY_FILE_ERROR -1
#define ARG_COUNT_ERROR -2
#define FILE_DOES_NOT_EXIST -3
#define UNKNOWN_PARAM -4
#define INPUT_ERROR -5

void c_param(char *count_str, char *file_poz);
void file_size_finder(FILE *file_name, int *count);
int p_param(char *file_name);
int s_param(char *file_name);