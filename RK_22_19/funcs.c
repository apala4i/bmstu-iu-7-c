#include "funcs.h"

int name_check(char surname[])
{
    int len = (int) strlen(surname);
    if (len < 5)
        return TOO_SHORT_SURNAME;
    char surname_check[MAX_SURNAME_LEN];
    strcpy(surname_check, surname);
    surname_check[4] = 0;

    for (int i = 0; i < 5; i++)
        surname_check[i] = (char)tolower(surname_check[i]);
    if (!strcmp("ivan", surname_check))
        return GOOD_SURNAME;
    else
        return BAD_SURNAME;
}

int num_checker(char num[])
{
    int num_len = (int) strlen(num);
    if (num_len != 11)
        return NOT_NUM;
    for (int i = 0; i < num_len; i++)
    {
        if (!isdigit(num[i]))
            return NOT_NUM;
    }
    return NUM;
}