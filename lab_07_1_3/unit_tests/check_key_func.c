#include "check_header.h"

START_TEST(test_key_one_positive_element)
        {
                int a[] = { 1 };
                int *beg = NULL;
                int *end = NULL;
                key(a, a + 1, &beg, &end);
                ck_assert_int_eq(beg[0], a[0]);
                free(beg);
        }
END_TEST

START_TEST(test_key_one_negative_element)
{
    int a[] = { -1 };
    int *beg = NULL;
    int *end = NULL;
    int rc = key(a, a + 1, &beg, &end);
    ck_assert_int_eq(EMPTY_RESULT, rc);
    free(beg);
}
END_TEST

START_TEST(test_key_few_positive_elements)
{
    int a[] = { 1, 2, 3, 4 };
    int *beg = NULL;
    int *end = NULL;
    key(a, a + 4, &beg, &end);
    for (size_t i = 0; i < 4; ++i)
    {
        ck_assert_int_eq(beg[i], a[i]);
    }
    free(beg);
}
END_TEST

START_TEST(test_key_few_negative_elemenst)
{
    int a[] = { -1, -2, -3, -4 };
    int *beg = NULL;
    int *end = NULL;
    key(a, a + 4, &beg, &end);
    for (size_t i = 0; i < 3; ++i)
    {
        ck_assert_int_eq(beg[i], a[i]);
    }
    free(beg);
}
END_TEST

START_TEST(test_key_few_negpos_elements)
{
    int a[] = { -1, -2, 3, 4 };
    int *beg = NULL;
    int *end = NULL;
    key(a, a + 4, &beg, &end);
    for (size_t i = 0; i < 1; ++i)
    {
        ck_assert_int_eq(beg[i], a[i]);
    }
    free(beg);
}
END_TEST

START_TEST(test_key_NULL_elements)
{
    int *beg = NULL;
    int *end = NULL;
    int rc = key(NULL, NULL, &beg, &end);
    ck_assert_int_eq(rc, INPUT_ERROR);
}
END_TEST

Suite *calc_key_suite(void)
{
    Suite *s;
    TCase *pos;
    TCase *neg;
    s = suite_create("key");

    pos = tcase_create("positives");
    tcase_add_test(pos, test_key_one_positive_element);
    tcase_add_test(pos, test_key_few_positive_elements);
    tcase_add_test(pos, test_key_one_negative_element);
    tcase_add_test(pos, test_key_few_negative_elemenst);
    tcase_add_test(pos, test_key_few_negpos_elements);
    suite_add_tcase(s, pos);

    neg = tcase_create("negative");
    tcase_add_test(neg, test_key_NULL_elements);

    suite_add_tcase(s, neg);

    return s;
}