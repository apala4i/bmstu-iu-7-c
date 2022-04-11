#ifndef SHEDULE_H
#define SHEDULE_H

#include "list.h"
int shReadFromFile(node_t **head, FILE *inputFile);
void shFreeShedule(node_t *head);
void shPrintAll(node_t *head);
void list_del_and_insert(node_t **head, char *value);
#endif