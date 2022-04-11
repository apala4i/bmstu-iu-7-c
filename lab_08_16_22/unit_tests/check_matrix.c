#include "check_header.h"

START_TEST(test_matrix_zero_sum_res)
{
    int rows = 2;
    int columns = 2;
    double res[][2] = {{0.0, 0.0}, {0.0, 0.0}};
    matrix test;
    ma_init_matrix(&test);
    ma_create_matrix(&test, 2, 2);

    matrix res_check;
    ma_init_matrix(&res_check);
    ma_create_matrix(&res_check, 2, 2);
    ma_zero_fill(&test);

    ma_matrix_sum(&res_check, &test, &test);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            ck_assert_double_eq(*ma_get_value(&res_check, i, j), res[i][j]);
        }
    }
    ma_clear(&test);
    ma_clear(&res_check);
}
END_TEST

START_TEST(test_matrix_not_zero_sum_res)
{
    int rows = 2;
    int columns = 2;
    double res[][2] = {{2.0, 2.0}, {2.0, 2.0}};
    matrix test;
    ma_init_matrix(&test);
    ma_create_matrix(&test, 2, 2);
    ma_set_value(&test, 0, 0, 1.);
    ma_set_value(&test, 0, 1, 1.);
    ma_set_value(&test, 1, 0, 1.);
    ma_set_value(&test, 1, 1, 1.);
    matrix res_check;
    ma_init_matrix(&res_check);
    ma_create_matrix(&res_check, 2, 2);

    ma_matrix_sum(&res_check, &test, &test);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            ck_assert_double_eq(*ma_get_value(&res_check, i, j), res[i][j]);
        }
    }
    ma_clear(&test);
    ma_clear(&res_check);
}
END_TEST

START_TEST
(test_matrix_dim_sum_error)
{
    matrix first;
    first.columns = 2;
    first.rows = 2;
    matrix second;
    second.rows = 1;
    second.columns = 1;
    int rc = ma_matrix_sum(NULL, &first, &second);
    ck_assert_int_eq(DIMENSION_ERROR, rc);
}
END_TEST



Suite *calc_matrix_sum_suite(void)
{
    Suite *s;
    TCase *pos;
    TCase *neg;
    s = suite_create("key");

    pos = tcase_create("positives");
    tcase_add_test(pos, test_matrix_zero_sum_res);
    tcase_add_test(pos, test_matrix_not_zero_sum_res);
    suite_add_tcase(s, pos);

    neg = tcase_create("negative");
    tcase_add_test(neg, test_matrix_dim_sum_error);
    suite_add_tcase(s, neg);

    return s;
}

START_TEST
(test_matrix_zero_mul_res)
{
    int rows = 2;
    int columns = 2;
    double res[][2] = {{0.0, 0.0}, {0.0, 0.0}};
    matrix test;
    ma_init_matrix(&test);
    ma_create_matrix(&test, 2, 2);
    ma_zero_fill(&test);

    matrix res_check;
    ma_init_matrix(&res_check);
    ma_create_matrix(&res_check, 2, 2);

    ma_matrix_mul(&res_check, &test, &test);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            ck_assert_double_eq(*ma_get_value(&res_check, i, j), res[i][j]);
        }
    }
    ma_clear(&test);
    ma_clear(&res_check);
}
END_TEST

START_TEST(test_matrix_not_zero_mul_res)
{
    int rows = 2;
    int columns = 2;
    double res[][2] = {{2.0, 2.0}, {2.0, 2.0}};
    matrix test;
    ma_init_matrix(&test);
    ma_create_matrix(&test, 2, 2);
    ma_set_value(&test, 0, 0, 1.);
    ma_set_value(&test, 0, 1, 1.);
    ma_set_value(&test, 1, 0, 1.);
    ma_set_value(&test, 1, 1, 1.);
    matrix res_check;
    ma_init_matrix(&res_check);
    ma_create_matrix(&res_check, 2, 2);

    ma_matrix_mul(&res_check, &test, &test);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            ck_assert_double_eq(*ma_get_value(&res_check, i, j), res[i][j]);
        }
    }
    ma_clear(&test);
    ma_clear(&res_check);
}
END_TEST

START_TEST(test_matrix_dim_mul_error)
{
    matrix first;
    first.columns = 2;
    first.rows = 2;
    matrix second;
    second.rows = 1;
    second.columns = 1;
    int rc = ma_matrix_mul(NULL, &first, &second);
    ck_assert_int_eq(DIMENSION_ERROR, rc);
}
END_TEST

Suite *calc_matrix_mul_suite(void)
{
    Suite *s;
    TCase *pos;
    TCase *neg;
    s = suite_create("key");

    pos = tcase_create("positives");
    tcase_add_test(pos, test_matrix_zero_mul_res);
    tcase_add_test(pos, test_matrix_not_zero_mul_res);
    suite_add_tcase(s, pos);

    neg = tcase_create("negative");
    tcase_add_test(neg, test_matrix_dim_mul_error);
    suite_add_tcase(s, neg);

    return s;
}

START_TEST(test_matrix_det_zero)
{
    matrix test;
    ma_init_matrix(&test);
    ma_create_matrix(&test, 2, 2);
    ma_set_value(&test, 0, 0, 1.);
    ma_set_value(&test, 0, 1, 1.);
    ma_set_value(&test, 1, 0, 1.);
    ma_set_value(&test, 1, 1, 1.);
    double res;
    ma_gauss_determinant_finder(&test, &res);
    ck_assert_double_eq(res, 0.0);
    ma_clear(&test);
}
END_TEST

START_TEST(test_matrix_det_not_zero)
{
    matrix test;
    ma_init_matrix(&test);
    ma_create_matrix(&test, 2, 2);
    ma_set_value(&test, 0, 0, 1.);
    ma_set_value(&test, 0, 1, 0.);
    ma_set_value(&test, 1, 0, 0.);
    ma_set_value(&test, 1, 1, 1.);
    double res;
    ma_gauss_determinant_finder(&test, &res);
    ma_clear(&test);
    ck_assert_double_eq(res, 1.0);
}
END_TEST

START_TEST(test_matrix_det_dim_error)
{
    matrix test;
    ma_init_matrix(&test);
    ma_create_matrix(&test, 2, 3);
    int rc;
    rc = ma_gauss_determinant_finder(&test, NULL);
    ma_clear(&test);
    ck_assert_int_eq(rc, NOT_SQUARE_MATRIX);
}
END_TEST

Suite *calc_matrix_det_suite(void)
{
    Suite *s;
    TCase *pos;
    TCase *neg;
    s = suite_create("key");

    pos = tcase_create("positives");
    tcase_add_test(pos, test_matrix_det_zero);
    tcase_add_test(pos, test_matrix_det_not_zero);
    suite_add_tcase(s, pos);

    neg = tcase_create("negative");
    tcase_add_test(neg, test_matrix_det_dim_error);
    suite_add_tcase(s, neg);

    return s;
}
