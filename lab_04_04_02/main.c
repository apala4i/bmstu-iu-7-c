#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_func.h"

#define N 257
#define MAX_MONTH_LEN 9
#define STABLE_WORK 0
#define INPUT_ERROR 1
#define LEN_ERROR 2

int main()
{
    char string[N];
    char temp[1];

    // string input
    if (!fgets(string, sizeof(string), stdin))
        return INPUT_ERROR;
    if (fgets(temp, sizeof(string), stdin))
        return LEN_ERROR;

    if (legit_check_date(string))
        printf("YES");
    else
        printf("NO");
    return STABLE_WORK;
}