#ifndef MY_STRING_H
#define MY_STRING_H

#define MAX_BUF 7

int my_strlen(const char *src);

int str_end_add(char *end, char *arg, int *cur_len, int max_len);

int hd_to_str(char *buf, int digit);

#endif