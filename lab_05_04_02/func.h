#ifndef FILE_H

#define FILE_H
#include "stdio.h"
//#include "stdint.h"
//#include "inttypes.h"
#include "string.h"
#include "stdlib.h"

#define MAX_NAME 30
#define MAX_MADE_BY 15

#define STABLE_WORK 0
#define UNKNOWN_PARAM 53
#define FILE_DOES_NOT_EXIST 2
#define EMPTY_FILE 3
#define INPUT_ERROR 4

struct product_info
{
    char name[MAX_NAME + 1];
    char made_by[MAX_MADE_BY + 1];
    unsigned int price;
    unsigned int count;
};

int sb_param(char *input_file_name, char *output_file_name);
int put_struct_by_pos(FILE *file, const int position, struct product_info *insert_product);
int get_struct_by_pos(FILE *file, const int position, struct product_info *current_product);
int ab_param(char *output_file_name);

int print_param(char *input_file_name);
int create_param(char *file_name);

#endif
