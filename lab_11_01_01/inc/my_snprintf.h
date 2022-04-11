#ifndef MY_SPRINTF_H
#define MY_SPRINTF_H
#include <stdio.h>

typedef enum
{
    string = 2,
    short_int = 3,
    strange
} types;

int my_snprintf(char *restrict buf, size_t num, const char *restrict format, ...);

#endif