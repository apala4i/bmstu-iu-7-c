#include "check_header.h"
#define EPS 0.00001


START_TEST(neg_test_NULL_structure_init)
{
    int rc = structures_init(NULL, 10);
    ck_assert_int_eq(EXIT_FAILURE, rc);
}
END_TEST

START_TEST(neg_test_bad_count_structure_init)
{
    struct objects test;
    int rc = structures_init(&test, -2);
    ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

START_TEST(pos_test_structure_init)
{
    int count = 10;
    int res = 0;
    struct objects *test;
    test = malloc(sizeof (struct objects) * count);
    structures_init(test, count);
    for (int i = 0; i < count; ++i)
    {
        res += (test[i].name == NULL);
    }
    free(test);
    ck_assert_int_eq(res, count);
}
END_TEST

START_TEST(neg_test_NULL_structures_clean)
{
    int rc = structures_clean(NULL, 10);
    ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

START_TEST(neg_test_bad_count_clean)
{
    struct objects test;
    int bad_count = -2;
    int rc = structures_clean(&test, bad_count);
    ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

START_TEST(pos_test_normal_clean)
{
    struct objects test[10];
    int count = 10;
    for (int i = 0; i < count; ++i)
    {
        test[i].name = malloc(sizeof (char));
    }

    structures_clean(test, count);
    int res = 0;
    for (int i = 0; i < count; ++i)
    {
        res += (test[i].name == NULL);
    }
    ck_assert_int_eq(res, count);
}
END_TEST

START_TEST(neg_count_structures_NULL_count)
{
    int rc = count_structures(NULL, stdin);
    ck_assert_int_eq(rc, BAD_ARGS);
}
END_TEST

START_TEST(neg_count_structures_NULL_input_file)
{
    int count = 10;
    int rc = count_structures(&count, NULL);
    ck_assert_int_eq(rc, BAD_ARGS);
}
END_TEST

START_TEST(pos_count_structure_one_structure)
{
    FILE *input_file = fopen("./unit_tests/one_struct.txt", "r");
    int count = 0;
    int rc = count_structures(&count, input_file);
    fclose(input_file);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(count, 1);
}
END_TEST

START_TEST(pos_count_structure_few_structure)
{
    FILE *input_file = fopen("./unit_tests/few_struct.txt", "r");
    int count = 0;
    int rc = count_structures(&count, input_file);
    fclose(input_file);
    ck_assert_int_eq(count, 2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(neg_read_structure_NULL_values)
{
    int rc = read_structures(NULL, stdin);
    ck_assert_int_eq(rc, BAD_ARGS);
}
END_TEST

START_TEST(neg_read_structure_NULL_input_file)
{
    struct objects test;
    int rc = read_structures(&test, NULL);
    ck_assert_int_eq(rc, BAD_ARGS);
}
END_TEST

START_TEST(pos_read_structure_one_struct)
{
    struct objects test[1];
    int res = 0;
    test[0].name = NULL;
    FILE *input_file = fopen("./unit_tests/one_struct.txt", "r");
    read_structures(test, input_file);
    fclose(input_file);
    if (strcmp(test[0].name, "testing\n") == 0)
    {
        res += 1;
    }
    if (test[0].mass - 123. <= EPS)
    {
        res += 1;
    }
    if (test[0].volume - 321. <= EPS)
    {
        res += 1;
    }
    free(test[0].name);
    ck_assert_int_eq(res, 3);
}
END_TEST

START_TEST(pos_read_structure_few_struct)
{
    struct objects test[2];
    int res = 0;
    test[0].name = NULL;
    test[1].name = NULL;
    FILE *input_file = fopen("./unit_tests/few_struct.txt", "r");
    read_structures(test, input_file);
    fclose(input_file);
    if (strcmp(test[0].name, "testing\n") == 0)
    {
        res += 1;
    }
    if (test[0].mass - 123. <= EPS)
    {
        res += 1;
    }
    if (test[0].volume - 321. <= EPS)
    {
        res += 1;
    }
    if (strcmp(test[1].name, "tester\n") == 0)
    {
        res += 1;
    }
    if (test[1].mass - 321. <= EPS)
    {
        res += 1;
    }
    if (test[1].volume - 123. <= EPS)
    {
        res += 1;
    }
    free(test[0].name);
    free(test[1].name);
    ck_assert_int_eq(6, res);
}
END_TEST

Suite *calc_funcs_suite(void)
{
    Suite *s;
    TCase *pos;
    TCase *neg;

    s = suite_create("funcs_test");
    pos = tcase_create("positives");
    tcase_add_test(pos, pos_count_structure_few_structure);
    tcase_add_test(pos, pos_count_structure_one_structure);
    tcase_add_test(pos, pos_read_structure_few_struct);
    tcase_add_test(pos, pos_read_structure_one_struct);
    tcase_add_test(pos, pos_test_normal_clean);
    tcase_add_test(pos, pos_test_structure_init);
    suite_add_tcase(s, pos);

    neg = tcase_create("negatives");
    tcase_add_test(neg, neg_count_structures_NULL_count);
    tcase_add_test(neg, neg_count_structures_NULL_input_file);
    tcase_add_test(neg, neg_read_structure_NULL_input_file);
    tcase_add_test(neg, neg_read_structure_NULL_values);
    tcase_add_test(neg, neg_test_NULL_structure_init);
    tcase_add_test(neg, neg_test_NULL_structures_clean);
    tcase_add_test(neg, neg_test_bad_count_clean);
    tcase_add_test(neg, neg_test_bad_count_structure_init);
    suite_add_tcase(s, neg);
    return s;
}
