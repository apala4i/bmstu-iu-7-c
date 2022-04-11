#include "func.h"

int get_number_by_pos(FILE *file, const int position, int *digit)
{
    unsigned int current_poz;
    current_poz = ftell(file);
    fseek(file, sizeof (int) * position, SEEK_SET);
    if (fread(digit, sizeof (int), 1, file) != 1)
        return INPUT_ERROR;
    fseek(file, current_poz, SEEK_SET);
    return STABLE_WORK;
}

int put_number_by_pos(FILE *file, const int position, const int insert_digit)
{
    unsigned int current_poz;
    current_poz = ftell(file);
    fseek(file, sizeof (int) * position, SEEK_SET);
    if (fwrite(&insert_digit, sizeof (int), 1, file) != 1)
        return INPUT_ERROR;
    fseek(file, current_poz, SEEK_SET);
    return STABLE_WORK;
}

void c_param(char *count_str, char *file_poz)
{
    int count = strtol(count_str, NULL, 10);
    FILE *file_name = fopen(file_poz, "wb");
    int rand_digit;
    for (int i = 0; i < count; i++)
    {
        rand_digit = rand() % 1000;
        fwrite(&rand_digit, sizeof rand_digit, 1, file_name);
    }
    printf("%d was successfully written to file %s\n", count, file_poz);
    fclose(file_name);
}

void file_size_finder(FILE *file_name, int *count)
{
    fseek(file_name, 0L, SEEK_END);
    *count = ftell(file_name);
    fseek(file_name, 0L, SEEK_SET);
}

int p_param(char *file_name)
{
    FILE *file = fopen(file_name, "rb");
    if (file == NULL)
        return FILE_DOES_NOT_EXIST;

    int count;
    file_size_finder(file, &count);
    count /= sizeof (int);
    if (count < 1)
        return EMPTY_FILE_ERROR;

    int current_digit;
    for (int i = 0; i < count; i++)
    {
        if (fread(&current_digit, sizeof current_digit, 1, file) != 1)
        {
            fclose(file);
            return INPUT_ERROR;
        }
        printf("%d\n", current_digit);
    }
    fclose(file);
    return STABLE_WORK;
}

int s_param(char *file_name)
{
    FILE *f = NULL;
    f = fopen(file_name, "rb+");

    if (f == NULL)
    {
        fclose(f);
        return FILE_DOES_NOT_EXIST;
    }

    fseek(f, 0, SEEK_END);
    int size = ftell(f) / sizeof(int);
    rewind(f);

    if (size == 0)
        return EMPTY_FILE_ERROR;

    int num_j, num_j_next;
    int tmp;
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1 - i; j++)
        {
            get_number_by_pos(f, j, &num_j);
            get_number_by_pos(f, j + 1, &num_j_next);
            if (num_j > num_j_next)
            {
                tmp = num_j;
                num_j = num_j_next;
                num_j_next = tmp;
            }
            put_number_by_pos(f, j, num_j);
            put_number_by_pos(f, j + 1, num_j_next);
        }

    fclose(f);
    return STABLE_WORK;
}