#include "../inc/funcs.h"

int main(int argc, char *argv[])
{
    // arg check
    if (argc != 2 && argc != 3)
    {
        return ARG_ERROR;
    }

    //making values and count
    struct objects *values = NULL;
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

    //structures count
    int rc = count_structures(&count, input_file);
    if (rc != EXIT_SUCCESS)
    {
        fclose(input_file);
        return rc;
    }

    // memory allocate
    values = malloc(sizeof (struct objects) * count);
    if (values == NULL)
    {
        return MEM_ERROR;
    }

    structures_init(values, count);

    //arg read
    rewind(input_file);
    rc = read_structures(values, input_file);
    fclose(input_file);
    if (rc != EXIT_SUCCESS)
    {
        free(values);
        return rc;
    }


    // if keys exists
    if (argc == 3)
    {
        if (strcmp(argv[2], "ALL") == 0)
        {
            print_structures(values, count);
            structures_clean(values, count);
            free(values);
            return EXIT_SUCCESS;
        }
        else
        {
            needle_values(values, count, argv[2]);
            structures_clean(values, count);
            free(values);
            return EXIT_SUCCESS;
        }
    }
    // if there are no keys
    else
    {
        bubble_sort_density(values, count);
        print_structures(values, count);
        structures_clean(values, count);
        free(values);
        return EXIT_SUCCESS;
    }
}