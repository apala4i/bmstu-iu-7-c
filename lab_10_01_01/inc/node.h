#ifndef NODE_H
#define NODE_H
#define _GNU_SOURCE

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *));

void *pop_end(node_t **head);

void append(node_t **head_a, node_t **head_b);

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));

node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

int push_front(node_t **head, void *element);

int node_free(node_t *head);

int node_count(node_t *head);

int get_int_by_pos(node_t *head, int index);

#endif