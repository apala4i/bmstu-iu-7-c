#include "shedule.h"
#include "stdlib.h"
#include "stdio.h"
#include "errors.h"
#include "string.h"

int shReadFromFile(node_t **head, FILE *inputFile)
{
    student_t *curStudent = NULL;
    int count = 0;
    int rc = EXIT_SUCCESS;

    while (rc == EXIT_SUCCESS)
    {
        rc = studReadStudent(inputFile, &curStudent);
        if (rc == EXIT_SUCCESS)
        {
            list_push_back(head, curStudent);
            count++;
        }
    }
    if (rc == EMPTY_FILE && count)
    {
        rc = EXIT_SUCCESS;
    }
    if (rc)
    {
        shFreeShedule(*head);
    }
    return rc;
}
void shPrintAll(node_t *head)
{
    while (head)
    {
        studPrintStudent(head->data);
        head = head->next;
    }
}

void shFreeShedule(node_t *head)
{
    node_t *realHead = head;
    while (head != NULL)
    {
        studFreeStudent(head->data);
        head = head->next;
    }
    list_node_free(realHead);
}

void list_del_and_insert(node_t **head, char *value)
{
    if ((*head)->next == NULL)
    {
        return;
    }
    node_t *cur = (*head)->next;
    node_t *prev = *head;
    node_t *proc = NULL;
    while (cur != NULL)
    {
        if (strcmp(cur->data->group, value) == 0)
        {
            prev->next = cur->next;
            proc = cur;
            cur = cur->next;
            proc->next = *head;
            *head = proc;
        }
        else
        {
            cur = cur->next;
            prev = prev->next;
        }
    }
}