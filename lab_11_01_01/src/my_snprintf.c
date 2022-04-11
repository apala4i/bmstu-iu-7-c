// Спецификаторы - %s %hd
#include "my_snprintf.h"
#include <stdarg.h>
#include "errors.h"
#include <stdbool.h>
#include <stdlib.h>
#include "my_string.h"

#define HD_BUF_LEN 10




static types spec_define(const char *str)
{
    types res = strange;
    if (str[0] == '%' && str[1] == 's')
    {
        res = string;
    }
    else if (str[0] == '%' && str[1] == 'h' && str[2] == 'd')
    {
        res = short_int;
    }
    return res;
}

int my_snprintf(char *restrict buf, size_t num, const char *restrict format, ...)
{
    int res_len = my_strlen(format);
    va_list vl;
    va_start(vl, format);
    int cur_ind = 0;
    int cur_buf = 0;
    while (format[cur_ind] != '\0')
    {
        if (format[cur_ind] != '%')
        {
            if (cur_buf + 1 < (int)num)
            {
                buf[cur_buf++] = format[cur_ind];
            }
            cur_ind++;
        }
        else
        {
            types res = spec_define(&format[cur_ind]);
            switch (res)
            {
                case string:
                    {
                        char *arg_str = va_arg(vl, char *);
                        res_len += my_strlen(arg_str) - 2;
                        str_end_add(&buf[cur_buf], arg_str, &cur_buf, (int) num);
                        cur_ind += 2;
                        break;
                    }
                case short_int:
                    {
                        short int arg_hd = (short int) va_arg(vl, int);
                        char hd_buf[HD_BUF_LEN];
                        hd_to_str(hd_buf, arg_hd);
                        res_len += my_strlen(hd_buf) - 3;
                        str_end_add(&buf[cur_buf], hd_buf, &cur_buf, (int) num);
                        cur_ind += 3;
                        break;
                    }
                default:
                    {
                        if (cur_buf + 1 < (int)num)
                        {
                            buf[cur_buf++] = format[cur_ind];
                        }
                        cur_ind += 1;
                    }
            }
        }
    }
    va_end(vl);
    if (num)
    {
        buf[cur_buf] = '\0';
    }
    return res_len;
}

//int main()
//{
//
//    size_t max_count = 8;
//    char buf[MAX_COUNT] = "asd";
//    char second_buf[MAX_COUNT] = "asd";
//
//    printf("before\n");
//    for (int i = 0; i < sizeof (second_buf); ++i)
//    {
//        printf("%c ", second_buf[i]);
//    }
//    printf("\n");
//
//    for (int i = 0; i < sizeof (buf); ++i)
//    {
//        printf("%c ", buf[i]);
//    }
//    printf("\n");
//
////    char *buf = "fffffffff";
////    char *second_buf = "fffffffff";
//    int res1 = 0, res2 = 0;
//    res1 = my_snprintf(buf, 0, "%s", "asd");
//    res2 = snprintf(second_buf, 0, "%s", "asd");
//
//    printf("after\n");
//    for (int i = 0; i < sizeof (buf); ++i)
//    {
//        printf("%c ", buf[i]);
//    }
//    printf("\n");
//
//
//    for (int i = 0; i < sizeof (second_buf); ++i)
//    {
//        printf("%c ", second_buf[i]);
//    }
//    printf("\n");
//
//
//    printf("res1 = %d\n%s", res1, buf);
//    printf("\nres2 = %d\n%s", res2, second_buf);
//}