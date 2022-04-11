#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME 30
#define MAX_GROUP 30

#include <stdio.h>


typedef struct
{
    char *name;
    int year;
    char *group;
}student_t;

int studReadStudent(FILE *inputFile, student_t **cur_student);

void studFreeStudent(student_t *student);

void studPrintStudent(student_t *student);

#endif