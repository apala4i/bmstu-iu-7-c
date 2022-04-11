#include "funcs.h"

int read_structures(struct objects *values, int *count, FILE *input_file)
{
    if (*count == MAX_STRUCTURES)
        return STRUCTURES_SIZE_ERROR;

    // create buffer for reading
    char buff[28]={0};

    // create symbol for correct reading
    char *check = NULL;

    // read from file
    while (!feof(input_file))
    {

        //structures size check
        if (*count == MAX_STRUCTURES)
            return STRUCTURES_SIZE_ERROR;

        // read name
        if (fgets(buff, sizeof buff, input_file) == NULL)
            return INPUT_ERROR;

        // check name size
        if (strlen(buff) > MAX_SIZE + 1 || strlen(buff) == 1)
            return NAME_SIZE_ERROR;

        // delete \n
        buff[strlen(buff) - 1] = 0;

        // fill structure.name
        strcpy(values[*count].name, buff);

        // read mass
        if (fgets(buff, sizeof buff, input_file) == NULL)
            return INPUT_ERROR;

        double value;
        // fill mass and check validity
        value = strtod(buff, &check);
        if (*check != '\n' && *check != '\0')
            return INPUT_ERROR;
        if (value <= 0.)
            return INPUT_ERROR;
        values[*count].mass = value;

        // read volume
        if (fgets(buff, sizeof buff, input_file) == NULL)
            return INPUT_ERROR;
        if (value <= 0.)
            return INPUT_ERROR;

        // fill volume and check validity
        value = strtod(buff, &check);
        if (*check != '\n' && *check != '\0')
            return INPUT_ERROR;
        values[*count].volume = value;

        // fill density
        values[*count].density = values[*count].mass / values[*count].volume;
        (*count)++;
    }

    return EXIT_SUCCESS;
}

void print_structures(struct objects *values, const int count)
{
    for (int i = 0; i < count; ++i)
    {
        printf("%s\n", values[i].name);
        printf("%.6lf\n", values[i].mass);
        printf("%.6lf\n", values[i].volume);
    }
}

void needle_values(const struct objects *values, const int count, const char *needle)
{
    for (int i = 0; i < count; ++i)
    {
        // check occurrence of needle
        if (strstr(values[i].name, needle) == values[i].name)
        {
            printf("%s\n", values[i].name);
            printf("%.6lf\n", values[i].mass);
            printf("%.6lf\n", values[i].volume);
        }
    }
}

void bubble_sort_density(struct objects *values, const int count)
{
    // create temp variable
    struct objects temp;

    // realization of bubble sorting
    for (int i = 0; i < count; ++i)
    {
        for (int j = 0; j < count - 1 - i; ++j)
        {
            if (values[j].density > values[j + 1].density)
            {
                temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }

        }
    }
}
