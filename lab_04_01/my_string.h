#define FOUND 1
#define NOT_FOUND 0

int my_strlen(const char *string)
{
    int count = 0;
    while (string[count++]);
    return --count;
}
int str_in(char symbol, const char *key)
{
    for (int i = 0; i < my_strlen(key); i++)
    {
        if (key[i] == symbol)
            return FOUND;
    }
    return NOT_FOUND;
}

int my_strspn(const char *string, const char *key)
{
    int count = 0;
    int flow;

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

int my_strcspn(const char *string, const char *key)
{
    int i = 0;
    while (!(str_in(string[i++], key)) && i <= my_strlen(string));
    return --i;
}