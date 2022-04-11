#include "funcs.h"

typedef enum
{
    positive, negative
} sign_define;

int process(FILE *f, int *count)
{
    *count = 0;
    float current_digit;
    sign_define sign;
    int flag = 0;
    if (fscanf(f, "%f", &current_digit) != 1 || ((int)current_digit) != current_digit)
        return EMPTY_SEQUENCE;
    if (current_digit >= 0)
        sign = positive;
    else
        sign = negative;
    while (fscanf(f, "%f", &current_digit) == 1 && ((int)current_digit) == current_digit)
    {
        flag += 1;
        if (current_digit >= 0 && sign == negative)
            *count += 1;
        if (current_digit < 0 && sign == positive)
            *count += 1;
        if (current_digit >= 0)
            sign = positive;
        else
            sign = negative;
    }

    if (!flag)
        return ONE_DIGIT_ERROR;
    return STABLE_WORK;
}