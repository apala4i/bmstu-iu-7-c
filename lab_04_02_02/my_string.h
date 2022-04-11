#define FOUND 1
#define NOT_FOUND 0
#define NO_WORDS 2
#define STABLE_WORK 0
#define WORD_LEN_ERROR 3
#define MAX_WORD 18

int my_strlen(const char *string)
{
    int count = 0;
    while (string[count++]);
    return --count;
}

int str_uniq(char *first, char *second)
{
    if (my_strlen(first) == my_strlen(second))
    {
        for (int i = 0; i < my_strlen(first); i++)
            if (first[i] != second[i])
                return 0;
        return 1;
    }
    return 0;
}

int str_uniq_maker(char string[][MAX_WORD], const int *count)
{
    for (int i = 0; i < *count - 1; i++)
    {
        for (int j = i + 1; j < *count; j++)
        {
            if (str_uniq(string[i], string[j]))
            {
                strcpy(string[j], "");
            }
        }
    }
    return STABLE_WORK;
}

int my_strspn(const char *string, const char *key)
{
    int flow = 0;
    int count = 0;
    for (int i = 0; i < my_strlen(string); i++)
    {
        flow = count;
        for (int j = 0; j < my_strlen(key); j++)
        {
            if (string[i] == key[j])
            {
                count++;
                break;
            }
        }
        if (!(flow - count))
            break;
    }
    return count;
}

int str_in_check(char word, char *key)
{
    for (int i = 0; i < my_strlen(key); i++)
    {
        if (word == key[i])
            return FOUND;
    }
    return NOT_FOUND;
}

int my_strtok(char *string, char words[][MAX_WORD], char *delims, int *count)
{
    int current_len = 0;
    int len = my_strlen(string);
    for (int i = 0; i < len; i++)
    {
        if (current_len >= 16)
            return WORD_LEN_ERROR;
        if (str_in_check(string[i], delims))
        {
            if (current_len)
            {
                string[i] = 0;
                strcpy(words[*count], &string[i - current_len]);
                current_len = 0;
                (*count)++;
            }
        }
        else
            current_len++;
    }
    if (current_len)
    {
        strcpy(words[*count], &string[len - current_len]);
        (*count)++;
    }
    if (!(*count))
        return NO_WORDS;
    return STABLE_WORK;
}

void str_n_del(char *string)
{
    char helper;
    for (int i = 0; i < my_strlen(string); i++)
        if (string[i] == '\n')
        {
            for (int j = i; j < my_strlen(string); j++)
            {
                helper = string[j];
                string[j] = string[j + 1];
                string[j + 1] = helper;
            }
        }
}