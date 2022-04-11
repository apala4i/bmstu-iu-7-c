#include "list.h"
#include "errors.h"
#include "stdlib.h"

static node_t *list_add_first(node_value element)
{
    node_t *res_node = malloc(sizeof (node_t));
    res_node->next = NULL;
    res_node->data = element;
    return res_node;
}

int list_node_free(node_t *head)
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

int list_push_front(node_t **head, node_value element)
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

// node_value = int
//void list_print_str(node_t *head, FILE *flow)
//{
//    if (!head)
//    {
//        printf("---");
//    }
//    while (head)
//    {
//        fprintf(flow, "%d ", head->data);
//        head = head->next;
//    }
//}

node_t *list_find_data(node_t *head, node_value data)
{
    while (head != NULL)
    {
        if (head->data == data)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

int list_get_len(node_t *head)
{
    int res_len = 0;
    for (; head; head = head->next)
    {
        res_len++;
    }
    return res_len;
}

int list_push_back(node_t **head, node_value element)
{
    int rc = EXIT_FAILURE;
    if (head)
    {
        rc = EXIT_SUCCESS;
        if (*head)
        {
            node_t *current_node = *head;
            while (current_node->next) {
                current_node = current_node->next;
            }
            node_t *new_node = malloc(sizeof(node_t));
            if (new_node) {
                new_node->next = NULL;
                new_node->data = element;
                current_node->next = new_node;
            }
        }
        else
        {
            *head = list_add_first(element);
        }
    }
    return rc;
}
