#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "digit.h"
#include "errors.h"
#include "defines.h"

void p_d_free(pow_digit *src)
{
    node_t *head = src->head;
    while (head != NULL)
    {
        free(head->data);
        head = head->next;
    }

    node_free(src->head);
}

int p_d_push_pow(pow_digit *src, const int pow)
{
    int *data = calloc(1, sizeof (int));
    if (data == NULL)
    {
        p_d_free(src);
        src->head = NULL;
        return MEM_ERROR;
    }

    *data = pow;

    if (push_back(&src->head, data) == MEM_ERROR)
    {
        p_d_free(src);
        src->head = NULL;
        return MEM_ERROR;
    }

    src->el_count += 1;
    return EXIT_SUCCESS;
}

int p_d_init(pow_digit *src)
{
    if (src == NULL)
    {
        return BAD_ARGS;
    }

    src->head = NULL;
    src->el_count = 0;
    return EXIT_SUCCESS;
}

static bool prime_check(int digit)
{
    if (digit < 2)
    {
        return false;
    }

    for (int i = 2; i * i <= digit; ++i)
    {
        if (digit % i == 0)
        {
            return false;
        }
    }
    return true;
}

static int next_prime(int *current_prime)
{
    if (!(prime_check(*current_prime)))
    {
        return BAD_ARGS;
    }

    *current_prime += *current_prime == 2 ? 1 : 2;
    while (!prime_check(*current_prime))
    {
        *current_prime += 2;
    }
    return EXIT_SUCCESS;
}

int p_d_convert(pow_digit *src, long long int digit)
{
    if (digit <= 0)
    {
        return BAD_DIGIT;
    }

    int current_prime = 2;
    int current_count = 0;

    while (digit > 1)
    {
        while (digit % current_prime == 0)
        {
            digit /= current_prime;
            ++current_count;
        }

        if (p_d_push_pow(src, current_count) == MEM_ERROR)
        {
            return MEM_ERROR;
        }
        src->el_count += 1;
        current_count = 0;
        next_prime(&current_prime);
    }
    return EXIT_SUCCESS;
}

long long int pow_long(long el, int pow)
{
    long long int res = 1;
    for (int i = 0; i < pow; ++i)
    {
        res *= el;
    }
    return res;
}

void p_d_print(const pow_digit *src, FILE *flow)
{
    node_t *curr_el = src->head;
    while (curr_el != NULL)
    {
        fprintf(flow, "%d ", *((int *)curr_el->data));
        curr_el = curr_el->next;
    }
    printf("L");

    if (DEBUG)
    {
        long long int res;
        p_d_back_to_digit(src, &res);
        printf("\ncheck res = %lld\n", res);
    }
}

int p_d_square(pow_digit *src)
{
    if (src == NULL)
    {
        return BAD_ARGS;
    }

    node_t *curr_el = src->head;
    int *curr_data;
    while (curr_el != NULL)
    {
        curr_data = curr_el->data;
        *curr_data += *curr_data;
        curr_el = curr_el->next;
    }
    return EXIT_SUCCESS;
}

int p_d_mul(pow_digit *first, pow_digit *second, pow_digit *res)
{
    p_d_init(res);

    node_t *first_el = first->head;
    node_t *second_el = second->head;
    while (first_el && second_el)
    {
        if (p_d_push_pow(res, *(int *)first_el->data + *(int *)second_el->data))
        {
            p_d_free(res);
            return MEM_ERROR;
        }

        first_el = first_el->next;
        second_el = second_el->next;
    }

    while (first_el)
    {
        if (p_d_push_pow(res, *(int *)first_el->data))
        {
            p_d_free(res);
            return MEM_ERROR;
        }
        first_el = first_el->next;
    }

    while (second_el)
    {
        if (p_d_push_pow(res, *(int *)second_el->data))
        {
            p_d_free(res);
            return MEM_ERROR;
        }
        second_el = second_el->next;
    }

    return EXIT_SUCCESS;
}

int p_d_back_to_digit(const pow_digit *src, long long int *res)
{
    if (src == NULL || res == NULL)
    {
        return BAD_ARGS;
    }

    int current_digit = 2;
    long long int current_res = 1;
    node_t *current_el = src->head;
    while (current_el != NULL)
    {
        if (*(int *)current_el->data != 0)
        {
            current_res *= pow_long(current_digit, *(int *)current_el->data);
        }
        next_prime(&current_digit);
        current_el = current_el->next;
    }
    *res = current_res;

    return EXIT_SUCCESS;
}


//FIXME: Что-то не так пошло. Я ушел спать.
int p_d_division(const pow_digit *first, const pow_digit *second, pow_digit *res)
{
    if (first == NULL || second == NULL || res == NULL)
    {
        return BAD_ARGS;
    }

    node_t *curr_first = first->head;
    node_t *curr_second = second->head;

    int *first_data;
    int *second_data;
    while (curr_first && curr_second)
    {
        first_data = (int *)curr_first->data;
        second_data = (int *)curr_second->data;
        if (*first_data > *second_data)
        {
            *first_data -= *second_data;
            *second_data = 0;
        }
        else if (*first_data + *second_data != 0)
        {
            *second_data -= *first_data;
            *first_data = 0;
        }
        curr_first = curr_first->next;
        curr_second = curr_second->next;
    }

    long long int res_first = 0;
    long long int res_second = 0;
    p_d_back_to_digit(first, &res_first);
    p_d_back_to_digit(second, &res_second);
    if (res_first < res_second)
    {
        return DIVISION_ERROR;
    }

    long long int res_value = res_first / res_second;
    p_d_init(res);
    if (p_d_convert(res, res_value))
    {
        return MEM_ERROR;
    }

    return EXIT_SUCCESS;
}
