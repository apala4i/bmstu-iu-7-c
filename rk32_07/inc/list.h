#ifndef _LIST_H
#define _LIST_H
#include <stdio.h>
#include "student.h"

typedef struct node node_t;
typedef student_t *node_value;

struct node
{
    node_value data;
    node_t *next;
};

node_t *list_find_data(node_t *head, node_value data);

int list_push_front(node_t **head, node_value data);

int list_node_free(node_t *head);

int list_get_len(node_t *head);

void list_print_str(node_t *head, FILE *flow);

int list_push_back(node_t **head, node_value element);

#endif