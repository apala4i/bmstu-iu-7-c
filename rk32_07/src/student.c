#include <student.h>
#include <stdlib.h>
#include <string.h>
#include <errors.h>

int studReadStudent(FILE *inputFile, student_t **cur_student)
{
    int rc = EXIT_FAILURE;
    *cur_student = malloc(sizeof (student_t));
    (*cur_student)->name = NULL;
    (*cur_student)->group = NULL;
    char *buf = NULL;
    size_t bufSize = 0;
    if (getline(&buf, &bufSize, inputFile) == -1)
    {
        rc = EMPTY_FILE;
    }
    else {
        if (strlen(buf) > MAX_NAME) {
            rc = INPUT_ERROR;
        } else {
            (*cur_student)->name = strdup(buf);
            if (getline(&buf, &bufSize, inputFile) != -1) {
                if (sscanf(buf, "%d", &((*cur_student)->year)) != 1) {
                    rc = INPUT_ERROR;
                } else {
                    if (getline(&buf, &bufSize, inputFile) != -1) {
                        if (strlen(buf) > MAX_GROUP) {
                            rc = INPUT_ERROR;
                        } else {
                            rc = EXIT_SUCCESS;
                            (*cur_student)->group = strdup(buf);
                        }
                    } else {
                        rc = INPUT_ERROR;
                    }
                }
            } else {
                rc = INPUT_ERROR;
            }
        }
    }
    if (rc)
    {
        free(buf);
        free(*
        cur_student);
        cur_student = NULL;
    }
    return rc;
}

void studFreeStudent(student_t *student)
{
    free(student->name);
    student->name = NULL;
    free(student->group);
    student->group = NULL;
    student->year = 0;
    free(student);
}

void studPrintStudent(student_t *student)
{
    printf("%s", student->name);
    printf("%d\n", student->year);
    printf("%s", student->group);
}