#include "my_string.h"
#include <stdbool.h>
#include <stdlib.h>

int my_strlen(const char *src)
{
    int res = 0;
    while (*src != '\0')
    {
        src += 1;
        res += 1;
    }
    return res;
}

int str_end_add(char *end, char *arg, int *cur_len, int max_len)
{
    int i = 0;
    int last_cur = *cur_len;
    while (arg[i] != '\0' && last_cur < max_len - 1)
    {
        if (max_len != 0 && end != NULL)
        {
            end[i] = arg[i];
        }
        ++i;
        last_cur += 1;
    }
    if (max_len)
    {
        *cur_len += my_strlen(arg);
        if (end)
        {
            end[i] = '\0';
        }
    }
    return my_strlen(arg);
}

int hd_to_str(char *buf, int digit)
{
    int digit_len = 0;
    int len_check = digit;
    bool sign = digit > 0 ? 0 : 1;
    if (digit == 0)
    {
        buf[0] = '0';
        buf[1] = '\0';
        digit_len = 1;
    }
    else
    {
        while (len_check)
        {
            len_check /= 10;
            digit_len += 1;
        }
        if (digit < 0)
        {
            digit *= -1;
        }
        buf[digit_len + sign] = '\0';
        if (sign)
        {
            buf[0] = '-';
        }
        for (int i = 0; i < digit_len; ++i)
        {
            buf[digit_len - i - !sign] = (char) ('0' + digit % 10);
            digit /= 10;
        }
    }
    return digit_len;
}
