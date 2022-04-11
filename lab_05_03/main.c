/*
 * Выбран знаковый целочисленный тип int.
 * Алгоритм сортировки - устойчивый.
 * Сортировка по возрастанию.
 */

#include "func.h"


int main(int argc, char *argv[])
{
    if (!strcmp(argv[1], "c"))
    {
        c_param(argv[2], argv[3]);
        return STABLE_WORK;
    }
    if (argc != 3)
    {
        printf("ARG_COUNT_ERROR");
        return ARG_COUNT_ERROR;
    }

    // file open
    if (!strcmp(argv[1], "p"))
    {
        if (p_param(argv[2]))
            return INPUT_ERROR;
        return STABLE_WORK;
    }

    if (!strcmp(argv[1], "s"))
    {
        if (s_param(argv[2]))
            return INPUT_ERROR;
        return STABLE_WORK;
    }

    printf("UNKNOWN_PARAM");
    return UNKNOWN_PARAM;
}
