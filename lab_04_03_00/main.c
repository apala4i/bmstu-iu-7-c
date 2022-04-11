#include <stdio.h>
#include <string.h>
#define M 17
#include "funcs.h"
#define SEPARATORS " ,;:-.!?"
#define WORD_LEN_ERROR 6
#define N 257
#define MAX_WORD 16
int main()
{
    char str[N];

//  input and check first string
    switch (input_string_checker(str, N))
    {
        case INPUT_ERROR:
            {
                printf("INPUT_ERROR");
                return INPUT_ERROR;
            }
        case EMPTY_STRING_ERROR:
            {
                printf("EMPTY_STRING_ERROR");
                return EMPTY_STRING_ERROR;
            }
        case LEN_ERROR:
            {
                printf("LEN_ERROR");
                return LEN_ERROR;
            }
    }

    char result[128][M];
    int count = 0;
    char *current;

    // word separating
    current = strtok(str, SEPARATORS);
    while (current != NULL)
    {
        if (strlen(current) > MAX_WORD)
        {
            printf("WORD_LEN_ERROR");
            return WORD_LEN_ERROR;
        }
        strcpy(result[count++], current);
        current = strtok(NULL, SEPARATORS);
    }

    if (count == 1)
    {
        printf("EMPTY_RESULT");
        return EMPTY_RESULT;
    }

    char new_str[N];
    new_str[0] = 0;
    if (last_word_del(result, count, new_str))
    {
        printf("EMPTY_RESULT");
        return NO_WORDS_ERROR;
    }
    printf("Result: %s\n", new_str);
    return OK;
}