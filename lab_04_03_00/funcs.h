#define OK 0
#define EMPTY_RESULT 1
#define INPUT_ERROR 4
#define LEN_ERROR 6
#define NO_WORDS_ERROR 2
#define EMPTY_STRING_ERROR 3

void str_n_del(char *string)
{
    char temp;
    for (int i = 0; i < strlen(string); i++)
        if (string[i] == '\n')
        {
            for (int j = i; j < strlen(string); j++)
            {
                temp = string[j];
                string[j] = string[j + 1];
                string[j + 1] = temp;
            }
        }
}

int input_string_checker(char *str, const int maximum)
{
    if (fgets(str, maximum + 1, stdin) == NULL)
    {
        return INPUT_ERROR;
    }
    str_n_del(str);
    if (strlen(str) == 0)
        return EMPTY_STRING_ERROR;
    if (strlen(str) >= maximum)
        return LEN_ERROR;
    return OK;
}

void str_first_keeper(char *string)
{
    int len = strlen(string);
    if (len == 1)
        return;
    char *temp;
    temp = strrchr(string, string[0]);
    while (temp != &string[0])
    {
        while (*temp != '\0')
        {
            *temp = *(temp + 1);
            temp++;
        }
        temp = strrchr(string, string[0]);
    }
}

int last_word_del(char words[][17], const int count, char *result)
{
    char *equal = words[count - 1];
    int len = count - 1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (strcmp(words[i], equal) != 0)
        {
            str_first_keeper(words[i]);
            strcat(result, words[i]);
            if ((i - 1) >= 0)
                strcat(result, " ");
        }
    }
    if (strlen(result) <= 1)
    {
        return NO_WORDS_ERROR;
    }
    return OK;
}