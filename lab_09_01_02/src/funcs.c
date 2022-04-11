#include "../inc/funcs.h"

// TODO: 
// - убрать ограничение по количеству.
// - убрать ограничение по размеру строки.
// - поменять структуру на динамическую.

int structures_init(struct objects *values, const int count)
{
    if (values == NULL || count < 1)
    {
        return EXIT_FAILURE;
    }
    for (int i = 0; i < count; ++i)
    {
        values[i].name = NULL;
    }
    return EXIT_SUCCESS;
}

int structures_clean(struct objects *values, const int count)
{
    if (values == NULL || count < 1)
    {
        return EXIT_FAILURE;
    }
    for (int i = 0; i < count; ++i)
    {
        free(values[i].name);
        values[i].name = NULL;
    }
    return EXIT_SUCCESS;
}


/**
 * @brief Counts structure elements and check validity.
 *
 * @param[out] count - count of structures.
 * @param[in] input_file - input stream.
 * @return int - error code:
 * INPUT ERROR - validity check failed.
 * EXIT_SUCCESS - structures counted successfully.
 * EMPTY_FILE - empty file.
 * BAD_ARGS - one of the arguments == NULL
 */
int count_structures(int *count, FILE *input_file)
{
    if (count == NULL || input_file == NULL)
    {
        return BAD_ARGS;
    }
    // create buffer for reading
    char *buff = NULL;
    size_t size = 0;

    // create symbol for correct reading
    char *check = NULL;

    // read from file
    while (!feof(input_file))
    {
        // read name
        if (getline(&buff, &size, input_file) == -1 || buff == NULL)
        {
            free(buff);
            if (*count == 0)
            {
                return EMPTY_FILE;
            }
            return EXIT_SUCCESS;
        }

        // read mass
        if (getline(&buff, &size, input_file) == -1 || buff == NULL)
        {
            free(buff);
            return INPUT_ERROR;
        }


        double value;
        // fill mass and check validity
        value = strtod(buff, &check);
        if (*check != '\n' && *check != '\r' && *check != '\0')
        {
            free(buff);
            return INPUT_ERROR;
        }
        if (value <= 0.)
        {
            free(buff);
            return INPUT_ERROR;
        }

        // read volume
        // read mass
        if (getline(&buff, &size, input_file) == -1 || buff == NULL)
        {
            free(buff);
            return INPUT_ERROR;
        }

        // fill volume and check validity
        value = strtod(buff, &check);
        if (value <= 0.)
        {
            free(buff);
            return INPUT_ERROR;
        }
        if (*check != '\n' && *check != '\r' && *check != '\0')
        {
            free(buff);
            return INPUT_ERROR;
        }
        (*count)++;
    }

    free(buff);
    return EXIT_SUCCESS;
}

int read_structures(struct objects *values, FILE *input_file)
{
    if (values == NULL || input_file == NULL)
    {
        return BAD_ARGS;
    }

    // create buffer for reading
    char *buff = NULL;
    size_t size = 0;

    char *tmp;

    int current_count = 0;

    // create symbol for correct reading
    char *check = NULL;

    // read from file
    while (!feof(input_file))
    {
        // read name
        if (getline(&buff, &size, input_file) == -1 || buff == NULL)
        {
            free(buff);
            if (current_count == 0)
            {
                return EMPTY_FILE;
            }
            return EXIT_SUCCESS;
        }

        if (strlen(buff) == 2 && buff[0] == '\r' && buff[1] == '\n')
        {
            free(buff);
            structures_clean(values, current_count + 1);
            return INPUT_ERROR;
        }

        if (strlen(buff) == 1 && buff[0] == '\n')
        {
            free(buff);
            structures_clean(values, current_count + 1);
            return INPUT_ERROR;
        }


        // write name
        tmp = strdup(buff);
        if (tmp == NULL)
        {
            free(buff);
            structures_clean(values, current_count + 1);
            return MEM_ERROR;
        }
        values[current_count].name = tmp;

        // read mass
        if (getline(&buff, &size, input_file) == -1 || buff == NULL)
        {
            free(buff);
            return INPUT_ERROR;
        }


        double value;
        // fill mass and check validity
        value = strtod(buff, &check);
        if ((*check != '\n' && *check != '\r' && *check != '\0') || value <= 0.)
        {
            free(buff);
            structures_clean(values, current_count + 1);
            return INPUT_ERROR;
        }

        values[current_count].mass = value;

        // read volume
        if (getline(&buff, &size, input_file) == -1 || buff == NULL)
        {
            free(buff);
            structures_clean(values, current_count + 1);
            return INPUT_ERROR;
        }

        // fill volume and check validity
        value = strtod(buff, &check);
        if ((*check != '\n' && *check != '\r' && *check != '\0') || value <= 0.)
        {
            free(buff);
            structures_clean(values, current_count + 1);
            return INPUT_ERROR;
        }

        values[current_count].volume = value;
        // fill density
        values[current_count].density = values[current_count].mass / values[current_count].volume;
        ++current_count;
    }

    free(buff);
    return EXIT_SUCCESS;
}

void print_structures(struct objects *values, const int count)
{
    for (int i = 0; i < count; ++i)
    {
        printf("%s", values[i].name);
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
            printf("%s", values[i].name);
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