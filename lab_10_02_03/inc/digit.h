#ifndef DIGIT_H
#define DIGIT_H

#include "node.h"

typedef struct
{
    node_t *head;
    int el_count;
}pow_digit;

void p_d_free(pow_digit *src);

int p_d_push_pow(pow_digit *src, const int pow);

int p_d_init(pow_digit *src);

int p_d_convert(pow_digit *src, long long int digit);

void p_d_print(const pow_digit *src, FILE *flow);

int p_d_square(pow_digit *src);

int p_d_mul(pow_digit *first, pow_digit *second, pow_digit *res);

int p_d_back_to_digit(const pow_digit *src, long long int *res);

int p_d_division(const pow_digit *first, const pow_digit *second, pow_digit *res);

#endif