#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mysort.h"
#include "defines.h"
#include "input.h"
#include "output.h"
#include "dlfcn.h"
typedef int (*kf_key)(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst, int *count);

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
    int size = 0;

    void *hlib;
    kf_key key;
    hlib = dlopen("libkey_func.so", RTLD_NOW);
    if (!hlib)
    {
        printf("dl library error\n");
        return DL_ERROR;
    }
    key = (kf_key) dlsym(hlib, "key");
//     if key in arguments
    if (argc == 4)
    {
        int rc = key(arr_begin, arr_end, &key_begin, &key_end, &size);
        if (rc)
        {
            free(arr_begin);
            arr_end = NULL;
            dlclose(hlib);
            return rc;
        }
        key_begin = malloc(size * sizeof (int));
        if (!key_begin)
        {
            free(arr_begin);
            arr_end = NULL;
            dlclose(hlib);
            return MEMORY_ERROR;
        }
        key(arr_begin, arr_end, &key_begin, &key_end, &size);

        free(arr_begin);
        arr_begin = key_begin;
        arr_end = key_end;
    }

    mysort(arr_begin, arr_end - arr_begin, sizeof(int), comp_for_int);

    if (print_to_file(arr_begin, arr_end, argv[2]))
    {
        free(arr_begin);
        dlclose(hlib);
//        printf("UNABLE_TO_CREATE_FILE");
        return UNABLE_TO_CREATE_FILE;
    }

    free(arr_begin);
    dlclose(hlib);
    return EXIT_SUCCESS;
}