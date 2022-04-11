#include "node.h"
#include <stdlib.h>
#include "errors.h"

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *))
{
    if (data == NULL)
    {
        return NULL;
    }
    while (head != NULL)
    {
        if (comparator(head->data, data) == 0)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void *pop_end(node_t **head)
{
    if (*head == NULL)
    {
        return NULL;
    }
    node_t *curr = *head;
    node_t *tmp;
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return curr;
    }
    while (curr->next != NULL)
    {
        tmp = curr;
        curr = curr->next;
    }
    tmp->next = NULL;
    void *data = curr->data;
    free(curr);
    return data;
}

/*!
 * \brief Функция добавляет список b в конец списка a и очищает список b.
 * @param head_a - начало первого списка.
 * @param head_b - начало второго списка.
 */
void append(node_t **head_a, node_t **head_b)
{
    if (*head_b == NULL)
    {
        return;
    }
    if (*head_a == NULL)
    {
        *head_a = *head_b;
        *head_b = NULL;
    }
    node_t *a_end = *head_a;
    while (a_end->next != NULL)
    {
        a_end = a_end->next;
    }
    a_end->next = *head_b;
    *head_b = NULL;
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    if (*head == NULL)
    {
        *head = element;
        (*head)->next = NULL;
        return;
    }
    node_t *beg_head = *head;
    if (comparator((*head)->data, element->data) >= 0)
    {
        *head = element;
        (*head)->next = beg_head;
        return;
    }

    node_t *tmp;
    while (beg_head != NULL && comparator(beg_head->data, element->data) < 0)
    {
        tmp = beg_head;
        beg_head = beg_head->next;
    }
    tmp->next = element;
    element->next = beg_head;
}

/*!
 * \brief Функция сортирует список из элементов node_t по возрастанию.
 *
 * @param[in] head - начало списка.
 *
 * @return node_t* - начало отсортированного списка.
 */
node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (head == NULL)
    {
        return NULL;
    }
    node_t *new_head = head;
    node_t *tmp;
    if (head->next == NULL)
    {
        return new_head;
    }
    head = head->next;
    new_head->next = NULL;
    while (head->next != NULL)
    {
        tmp = head;
        head = head->next;
        sorted_insert(&new_head, tmp, comparator);
    }
    sorted_insert(&new_head, head, comparator);
    return new_head;
}

int push_front(node_t **head, void *element)
{
    node_t *new_head = malloc(sizeof (node_t));
    if (new_head == NULL)
    {
        return MEM_ERROR;
    }

    new_head->data = element;
    node_t *tmp = *head;
    *head = new_head;
    new_head->next = tmp;
    return EXIT_SUCCESS;
}

int node_free(node_t *head)
{
    if (head == NULL)
    {
        return BAD_ARGS;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return EXIT_SUCCESS;
    }
    node_t *tmp;
    while (head->next != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
        tmp = NULL;
    }
    free(head);
    head = NULL;
    return EXIT_SUCCESS;
}

// funcs for units
int node_count(node_t *head)
{
    int res = 0;
    while (head != NULL)
    {
        head = head->next;
        ++res;
    }
    return res;
}

int get_int_by_pos(node_t *head, int index)
{
    int cur_index = 0;
    if (head == NULL)
    {
        return -1;
    }
    while (head->next != NULL && index != cur_index)
    {
        head = head->next;
        ++cur_index;
    }
    int res = *((int *)(head->data));
    return res;
}