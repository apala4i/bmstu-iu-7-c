#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/mysort.h"
#include "../inc/defines.h"
#include "../inc/input.h"
#include "../inc/output.h"
#include "../inc/key_func.h"

int main(int argc, char *argv[])
{
    // check validity of arguments from console
    if (argc != 3 && argc != 4)
    {
//        printf("ARG_ERROR");
        return ARG_ERROR;
    }

    if (argc == 4 && strcmp(argv[3], "f") != 0)
    {
//        printf("ARG_ERROR");
        return ARG_ERROR;
    }

    // count of digits in file
    int count = 0;

    // try to open the file
    switch (digits_counter(argv[1], &count))
    {
        case INPUT_ERROR:
//            printf("INPUT_ERROR");
            return INPUT_ERROR;
        case FILE_DOES_NOT_EXIST:
//            printf("FILE_DOES_NOT_EXIST");
            return FILE_DOES_NOT_EXIST;
        case EMPTY_FILE:
//            printf("EMPTY_FILE");
            return EMPTY_FILE;
    }

    int *arr_begin = NULL;
    int *arr_end = NULL;

    switch (make_and_fill(argv[1], count, &arr_begin, &arr_end))
    {
        case FILE_DOES_NOT_EXIST:
//            printf("FILE_DOES_NOT_EXIST");
            return FILE_DOES_NOT_EXIST;
        case MEM_ERROR:
//            printf("MEM_ERROR");
            return MEM_ERROR;
    }

    int *key_begin = NULL;
    int *key_end = NULL;

//     if key in arguments
    if (argc == 4)
    {
        int rc = key(arr_begin, arr_end, &key_begin, &key_end);
        if (rc)
        {
            free(arr_begin);
            arr_end = NULL;
            return rc;
        }
        free(arr_begin);
        arr_begin = key_begin;
        arr_end = key_end;
    }

    mysort(arr_begin, arr_end - arr_begin, sizeof(int), comp_for_int);

    if (print_to_file(arr_begin, arr_end, argv[2]))
    {
        free(arr_begin);
//        printf("UNABLE_TO_CREATE_FILE");
        return UNABLE_TO_CREATE_FILE;
    }

    free(arr_begin);

    return EXIT_SUCCESS;
}