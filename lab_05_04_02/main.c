#include "func.h"

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);

    if (argc < 2)
        return UNKNOWN_PARAM;
    // help params
//    if (!strcmp(argv[1], "print"))
//    {
//        print_param(argv[2]);
//        return STABLE_WORK;
//    }
//
//    if (!strcmp(argv[1], "create"))
//    {
//        create_param(argv[2]);
//        return STABLE_WORK;
//    }


    // check param sb
    if (!strcmp(argv[1], "sb"))
    {
        if (argc != 4)
        {
            printf("WRONG_PARAM");
            return UNKNOWN_PARAM;
        }
        switch (sb_param(argv[2], argv[3]))
        {
            case FILE_DOES_NOT_EXIST:
                {
                    printf("FILE_DOES_NOT_EXIST");
                    return FILE_DOES_NOT_EXIST;
                }
            case EMPTY_FILE:
                {
                    printf("EMPTY_FILE");
                    return EMPTY_FILE;
                }
            case INPUT_ERROR:
                {
                    printf("INPUT_ERROR");
                    return INPUT_ERROR;
                }
        }
        return STABLE_WORK;
    }

    // check param ab
    if (!strcmp(argv[1], "ab"))
    {
        if (argc != 3)
        {
            printf("WRONG_PARAM");
            return UNKNOWN_PARAM;
        }
        switch (ab_param(argv[2]))
        {
            case FILE_DOES_NOT_EXIST:
                {
                    printf("FILE_DOES_NOT_EXIST");
                    return FILE_DOES_NOT_EXIST;
                }
            case EMPTY_FILE:
                {
                    printf("EMPTY_FILE");
                    return EMPTY_FILE;
                }
            case INPUT_ERROR:
                {
                    printf("INPUT_ERROR");
                    return INPUT_ERROR;
                }
        }
        return STABLE_WORK;
    }

    //if param neither ab nor sb return unknown param error
    printf("UNKNOWN PARAM");
    return UNKNOWN_PARAM;
}
