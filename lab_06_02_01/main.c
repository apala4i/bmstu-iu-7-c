#include "funcs.h"

int main(int argc, char *argv[])
{
    // arg check
    if (argc != 2 && argc != 3)
    {
        printf("ARG_ERROR");
        return ARG_ERROR;
    }

    //making values and count
    struct objects values[15];
    int count = 0;

    // open file and check it existent
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
        return FILE_DOES_NOT_EXIST;

    // file not empty
    if (feof(input_file))
        return EMPTY_FILE;

    //arg read
    switch (read_structures(values, &count, input_file))
    {
        case FILE_DOES_NOT_EXIST:
            fclose(input_file);
            printf("FILE_DOES_NOT_EXIST");
            return EXIT_FAILURE;
        case EMPTY_FILE:
            fclose(input_file);
            printf("EMPTY_FILE");
            return EXIT_FAILURE;
        case INPUT_ERROR:
            fclose(input_file);
            printf("INPUT_ERROR");
            return EXIT_FAILURE;
        case NAME_SIZE_ERROR:
            fclose(input_file);
            printf("NAME_SIZE_ERROR");
            return EXIT_FAILURE;
        case STRUCTURES_SIZE_ERROR:
            fclose(input_file);
            printf("STRUCTURES_SIZE_ERROR");
            return EXIT_FAILURE;
        default:
            fclose(input_file);
    }

    // if keys exists
    if (argc == 3)
    {
        if (strcmp(argv[2], "ALL") == 0)
        {
            print_structures(values, count);
            return EXIT_SUCCESS;
        }
        else
        {
            needle_values(values, count, argv[2]);
            return EXIT_SUCCESS;
        }
    }

    // if there are no keys
    else
    {
        bubble_sort_density(values, count);
        print_structures(values, count);
        return EXIT_SUCCESS;
    }
}