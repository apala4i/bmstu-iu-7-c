#include "funcs.h"

int main(int argc, char *argv[])
{
    // arg check
    if (argc != 2 && argc != 3)
    {
        return ARG_ERROR;
    }

    //making values and count
    struct objects values[15];
    int count = 0;

    // open file and check it existent
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        return FILE_DOES_NOT_EXIST;
    }

    // file not empty
    if (feof(input_file))
    {
        return EMPTY_FILE;
    }

    //arg read
    switch (read_structures(values, &count, input_file))
    {
        case EXIT_SUCCESS:
            fclose(input_file);
            break;
        default:
            fclose(input_file);
            return EXIT_FAILURE;
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
