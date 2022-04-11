#include <stdio.h>
#include "funcs.h"

int main(int args, char *kargs[])
{
    FILE *file_name = fopen(kargs[1], "rb");
    if (file_name == NULL)
    {
        printf("FILE_DOES_NOT_EXIST");
        return FILE_DOES_NOT_EXIST;
    }

    int correct_count = 0;
    subscriber current_sub;
    while (fread(&current_sub, sizeof current_sub, 1, file_name) == 1)
    {
        if (name_check(current_sub.surname) == GOOD_SURNAME && num_checker(current_sub.number) == NUM)
                {
                    correct_count += 1;
                    printf("%s  %s\n", current_sub.surname, current_sub.number);
                }
    }
    if (!correct_count)
    {
        printf("THERE ARE NO SUCH SUBSCRIBERS");
        return NOT_FOUND;
    }
    return 0;

}
