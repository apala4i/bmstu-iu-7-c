#include <stdio.h>
#include "funcs.h"

int main()
{
    int count;
    switch (process(stdin, &count))
    {
        case EMPTY_SEQUENCE:
            {
                printf("EMPTY_SEQUENCE");
                return EMPTY_SEQUENCE;
            }
        case ONE_DIGIT_ERROR:
            {
                printf("ONE_DIGIT_ERROR");
                return ONE_DIGIT_ERROR;
            }
    }
    printf("%d", count);
    return STABLE_WORK;
}
