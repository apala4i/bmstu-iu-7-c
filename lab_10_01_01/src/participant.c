#include "participant.h"
#include "stdio.h"
#include "stdlib.h"
#include "errors.h"
#include "string.h"
#include "limits.h"

int clean_part(participant *storage, const int count)
{
    if (count < 1)
    {
        return EXIT_FAILURE;
    }
    if (storage == NULL)
    {
        return EXIT_FAILURE;
    }
    for (int i = 0; i < count; ++i)
    {
        free(storage[i].name);
        storage[i].name = NULL;
        storage[i].age = -1;
        storage[i].level = -1;
    }
    return EXIT_SUCCESS;
}

int count_part(FILE *input_file, int *count)
{
    char *buff = NULL;
    char *check = NULL;
    long digit_check;
    size_t len;
    while (!feof(input_file))
    {
        if (getline(&buff, &len, input_file) == -1)
        {
            free(buff);
            if (*count == 0)
            {
                return EMPTY_FILE;
            }
            return EXIT_SUCCESS;
        }
        if (getline(&buff, &len, input_file) == -1)
        {
            free(buff);
            return INPUT_ERROR;
        }

        digit_check = strtol(buff, &check, 10);
        if (!((strlen(check) == 2 && check[0] == '\r' && check[1] == '\n')
            || (strlen(check) == 1 && check[0] == '\n') || strlen(check) == 0))
        {
            free(buff);
            return INPUT_ERROR;
        }
        if (digit_check > SHRT_MAX || digit_check < SHRT_MIN)
        {
            free(buff);
            return INPUT_ERROR;
        }

        if (getline(&buff, &len, input_file) == -1)
        {
            free(buff);
            return INPUT_ERROR;
        }

        digit_check = strtol(buff, &check, 10);
        if (!((strlen(check) == 2 && check[0] == '\r' && check[1] == '\n')
            || (strlen(check) == 1 && check[0] == '\n') || strlen(check) == 0))
        {
            free(buff);
            return INPUT_ERROR;
        }
        if (digit_check < 0 || digit_check > 2)
        {
            free(buff);
            return INPUT_ERROR;
        }

        *count += 1;
    }
    return EXIT_SUCCESS;
}

int read_part(FILE *input_file, participant *storage)
{
    if (storage == NULL || input_file == NULL)
    {
        return BAD_FUNC_ARGS;
    }
    char *buff = NULL;
    char *check = NULL;
    size_t len;
    char *tmp = NULL;
    int current_count = 0;
    while (!feof(input_file))
    {
        if (getline(&buff, &len, input_file) == -1)
        {
            free(buff);
            if (current_count == 0)
            {
                return EMPTY_FILE;
            }
            return EXIT_SUCCESS;
        }

        if (strlen(buff) == 1)
        {
            free(buff);
            return INPUT_ERROR;
        }

        tmp = strdup(buff);
        if (tmp == NULL)
        {
            clean_part(storage, current_count);
            free(buff);
            return MEM_ERROR;
        }

        storage[current_count].name = tmp;

        getline(&buff, &len, input_file);
        storage[current_count].age = (short)strtol(buff, &check, 10);

        getline(&buff, &len, input_file);
        storage[current_count].level = (short)strtol(buff, &check, 10);;

        current_count += 1;
    }
    return EXIT_SUCCESS;
}

int participant_init(participant **storage, const int count)
{
    if (count < 1)
    {
        return BAD_ARGS;
    }
    *storage = (participant *)malloc(sizeof (participant) * count);
    if (*storage == NULL)
    {
        return MEM_ERROR;
    }
    for (int i = 0; i < count; ++i)
    {
        (*storage)[i].name = NULL;
        (*storage)[i].level = -1;
        (*storage)[i].age = -1;
    }
    return EXIT_SUCCESS;
}
