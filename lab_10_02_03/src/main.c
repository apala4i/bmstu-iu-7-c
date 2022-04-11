#include <stdio.h>
#include <string.h>
#include "digit.h"
#include "errors.h"
#include "defines.h"

//FIXME: Возможно 0 это негатив
int main()
{
    int rc;
    char choice[10];
    if (fgets(choice, CHOICE_LEN, stdin) == NULL)
    {
        rc = INPUT_ERROR;
    }
    else
    {
        if (choice[strlen(choice) - 1] == '\n')
        {
            choice[strlen(choice) - 1] = '\0';
        }
        long long first_value = 0;
        long long second_value = 0;
        pow_digit first;
        p_d_init(&first);
        pow_digit second;
        p_d_init(&second);
        pow_digit res;
        p_d_init(&res);
        if (strcmp(choice, "out") == 0 || strcmp(choice, "sqr") == 0)
        {
            if (scanf("%lld", &first_value) != 1)
            {
                rc = INPUT_ERROR;
            }
            else
            {
                rc = p_d_convert(&first, first_value);
                if (!rc)
                {
                    if (strcmp(choice, "sqr") == 0)
                    {
                        p_d_square(&first);
                    }
                    p_d_print(&first, stdout);
                }
            }
        }
        else if (strcmp(choice, "mul") == 0 || strcmp(choice, "div") == 0)
        {
            if (scanf("%lld\n%lld", &first_value, &second_value) != 2)
            {
                rc = INPUT_ERROR;
            }
            else
            {
                rc = p_d_convert(&first, first_value);
                if (!rc)
                {
                    rc = p_d_convert(&second, second_value);
                    if (!rc)
                    {
                        if (strcmp(choice, "mul") == 0)
                        {
                            rc = p_d_mul(&first, &second, &res);
                        }
                        else
                        {
                            rc = p_d_division(&first, &second, &res);
                        }
                        if (!rc)
                        {
                            p_d_print(&res, stdout);
                        }
                    }
                }
            }
        }
        else
        {
            rc = INPUT_ERROR;
        }
        p_d_free(&first);
        p_d_free(&second);
        p_d_free(&res);
    }

    return rc;
}