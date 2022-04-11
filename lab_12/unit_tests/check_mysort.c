#include "check_header.h"

START_TEST(test_mysort_one_int)
        {
                int a[] = { 1 };

                mysort(a, 1, sizeof(int), comp_for_int);
                // Внутри функции-теста проверки реализуются с помощью ck_assert_XYZ. Познакомьтесь
                // с этими функциями в документации.
                ck_assert_int_eq(a[0], 1);
        }
END_TEST


START_TEST(test_mysort_few_int)
{
    int a[] = { 3, -2, 1, 4 };
    int res[] = { -2, 1, 3, 4 };
    mysort(a, 4, sizeof(int), comp_for_int);
    for (size_t i = 0; i < 4; ++i)
    {
        ck_assert_int_eq(a[i], res[i]);
    }
}
END_TEST

START_TEST(test_mysort_one_float)
{
    float a[] = { 2.2f };

    mysort(a, 1, sizeof(float), comp_for_float);
    ck_assert_float_eq(a[0], 2.2f);
}
END_TEST

START_TEST(test_mysort_few_float)
{
    float a[] = { 3.f, -2.f, 1.f, 4.f };
    float res[] = { -2.f, 1.f, 3.f, 4.f };
    mysort(a, 4, sizeof(float), comp_for_float);
    for (size_t i = 0; i < 4; ++i)
    {
        ck_assert_float_eq(a[i], res[i]);
    }
}
END_TEST


START_TEST(test_mysort_one_char)
{
    char a[] = { 'a' };

    mysort(a, 1, sizeof(char), comp_for_char);
    ck_assert_int_eq((int) a[0], (int) 'a');
}
END_TEST

START_TEST(test_mysort_few_char)
{
    char a[] = { 'b', 'c', 'a', 'e' };
    char res[] = { 'a', 'b', 'c', 'e' };
    mysort(a, 4, sizeof(char), comp_for_char);
    for (size_t i = 0; i < 4; ++i)
    {
        ck_assert_float_eq((int) a[i], (int) res[i]);
    }
}
END_TEST

START_TEST(test_mysort_empty)
{
    int rc = mysort(NULL, 2, sizeof(int), comp_for_int);
    ck_assert_int_eq(rc, NULL_ERROR);
}
END_TEST

START_TEST(test_mysort_bad_count)
{
    int a[] = { 1, 2, 3, 4 };
    int rc = mysort(a, -2, sizeof(int), comp_for_int);
    ck_assert_int_eq(rc, EMPTY_SEQUENCE);
}
END_TEST

Suite *calc_mysort_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("mysort");

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_mysort_empty);
    tcase_add_test(tc_neg, test_mysort_bad_count);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_mysort_one_int);
    tcase_add_test(tc_pos, test_mysort_few_int);
    tcase_add_test(tc_pos, test_mysort_one_float);
    tcase_add_test(tc_pos, test_mysort_few_float);
    tcase_add_test(tc_pos, test_mysort_one_char);
    tcase_add_test(tc_pos, test_mysort_few_char);

    suite_add_tcase(s, tc_pos);

    return s;
}