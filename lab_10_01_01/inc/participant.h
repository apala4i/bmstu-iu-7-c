#ifndef PARTICIPANTS_H
#define PARTICIPANTS_H
#define _GNU_SOURCE

#include <stdio.h>

typedef struct
{
    char *name;
    short age;
    short level;
}participant;

int clean_part(participant *storage, const int count);

int count_part(FILE *input_file, int *count);

int read_part(FILE *input_file, participant *storage);

int participant_init(participant **storage, const int count);


#endif
