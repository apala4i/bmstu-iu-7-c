#include "shedule.h"
#include "stdio.h"
#include "errors.h"

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        FILE *inputFile = fopen(argv[1], "r");
        if (fgetc(inputFile) && feof(inputFile))
        {
            printf("EMPTY_FILE");
            fclose(inputFile);
            return EMPTY_FILE;
        }
        rewind(inputFile);
        if (inputFile)
        {
            node_t *shedule = NULL;
            if (shReadFromFile(&shedule, inputFile))
            {
                printf("INPUT_ERROR");
                return INPUT_ERROR;
            }
            else
            {
                printf("До сортировки\n");
                shPrintAll(shedule);
                list_del_and_insert(&shedule, "asd\n");
                printf("После сортировки\n");
                shPrintAll(shedule);
            }
        }
        else
        {
            printf("FILE_ERROR\n");
            return FILE_ERROR;
        }
        fclose(inputFile);
    }
    else
    {
        printf("ARG ERROR\n");
        return BAD_ARGS;
    }
    return 0;
}