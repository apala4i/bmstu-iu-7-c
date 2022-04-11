#include <stdio.h>
#include <string.h>

#define SEPARATORS " ,;:-.!?"
#define INPUT_ERROR 3
#define SIZE_ERROR 4
#define EMPTY_STRING_ERROR 5
#define N 257
#include "my_string.h"

int string_checker(char *string, int max_count)
{
    if (fgets(string, max_count + 1, stdin) == NULL)
        return INPUT_ERROR;
    str_n_del(string);
    if (my_strlen(string) >= max_count)
        return SIZE_ERROR;
    if (my_strlen(string) == 0)
        return EMPTY_STRING_ERROR;
    return STABLE_WORK;
}

int main()
{
    setbuf(stdin, NULL);
    printf("Input string\n");
    char string[N];

    // string input
    switch (string_checker(string, N))
    {
        case INPUT_ERROR:
            {
                printf("INPUT_ERROR");
                return INPUT_ERROR;
            }
        case SIZE_ERROR:
            {
                printf("SIZE_ERROR");
                return SIZE_ERROR;
            }
        case EMPTY_STRING_ERROR:
            {
                printf("EMPTY_STRING_ERROR");
                return EMPTY_STRING_ERROR;
            }
    }

    char key[N];

    // key input
    switch (string_checker(key, N))
    {
        case INPUT_ERROR:
            {
                printf("INPUT_ERROR");
                return INPUT_ERROR;
            }
        case SIZE_ERROR:
            {
                printf("SIZE_ERROR");
                return SIZE_ERROR;
            }
        case EMPTY_STRING_ERROR:
            {
                printf("EMPTY_STRING_ERROR");
                return EMPTY_STRING_ERROR;
            }
    }

    char result[N][MAX_WORD];
    int count = 0;

    switch (my_strtok(string, result, SEPARATORS, &count))
    {
        case NO_WORDS:
            {
                printf("NO_WORDS");
                return NO_WORDS;
            }
        case WORD_LEN_ERROR:
            {
                printf("WORD_LEN_ERROR");
                return WORD_LEN_ERROR;
            }
    }

    char keys[N][MAX_WORD];

    int keys_count = 0;

    // keys word separating
    switch (my_strtok(key, keys, SEPARATORS, &keys_count))
    {
        case NO_WORDS:
            {
                printf("NO_WORDS");
                return NO_WORDS;
            }
        case WORD_LEN_ERROR:
            {
                printf("WORD_LEN_ERROR");
                return WORD_LEN_ERROR;
            }
    }

    // making uniq elements
    str_uniq_maker(result, &count);

    // printing result
    printf("Result:\n");
    for (int i = 0; i < count; i++)
        if (strlen(result[i]) != 0)
        {
            for (int j = 0; j < keys_count; j++)
            {
                if (!strcmp(result[i], keys[j]))
                {
                    printf("%s yes\n", result[i]);
                    break;
                }
                else if (j + 1 == keys_count)
                    printf("%s no\n", result[i]);
            }
        }
    return STABLE_WORK;
}