#ifndef CHECK_HEADER_H
#define CHECK_HEADER_H

#include <stdlib.h>
#include <check.h>
#include "../inc/matrix.h"
#include "../inc/error.h"

Suite *calc_matrix_mul_suite(void);
Suite *calc_matrix_sum_suite(void);
Suite *calc_matrix_det_suite(void);

#endif
