#include <check.h>
#include "node.h"
#include "errors.h"
#include <stdlib.h>

int node_comp_int(const void *first, const void *second)
{
    return *((int *)first) - *((int *)second);
}

START_TEST(pos_node_find)
{
    node_t *test = NULL;
    int size = 4;
    int values[] = {1, 2, 3, 4};
    for (int i = 0; i < size; ++i)
    {
        push_front(&test, &values[i]);
    }
    int res = 0;
    res += (*((int *)(find(test, &values[2],node_comp_int)->data)) == values[2]);
    node_free(test);
    ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(neg_node_find_NULL_data)
{
    node_t *test = NULL;
    int res = 0;
    res += (find(test, NULL, node_comp_int)) == NULL;
    ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(pos_pop_end_test)
{
    int check = 0;
    int count = 4;
    int elements[] = {1, 2, 3, 4};
    node_t *head = NULL;
    for (int i = 0; i < count; ++i)
    {
        push_front(&head, &elements[i]);
    }
    int *del_el = pop_end(&head);
    check += (del_el == &elements[0]);
    node_free(head);
    ck_assert_int_eq(check, 1);
}
END_TEST

START_TEST(neg_node_free_NULL_head)
{
    node_t *head = NULL;
    ck_assert_int_eq(BAD_ARGS, node_free(head));
}
END_TEST


START_TEST(pos_push_front_test)
{
    node_t *head = NULL;
    int hope_count = 4;
    int arr[] = {1, 2, 3, 4};
    for (int i = 0; i < hope_count; ++i)
    {
        push_front(&head, &arr[i]);
    }
    int real_count = node_count(head);
    node_free(head);
    ck_assert_int_eq(real_count, hope_count);
}
END_TEST

START_TEST(neg_sort_NULL_head_test)
{
    node_t *test = NULL;
    int check = 0;
    check += (sort(test, node_comp_int) == NULL);
    ck_assert_int_eq(check, 1);
}
END_TEST

START_TEST(pos_sort_test)
{
    node_t *test = NULL;
    int res = 0;
    int not_sorted_arr[] = {3, 1, 2, 0};
    for (int i = 0; i < 4; ++i)
    {
        push_front(&test, &not_sorted_arr[i]);
    }
    test = sort(test, node_comp_int);
    for (int i = 0; i < 4; ++i)
    {
        res += (get_int_by_pos(test, i) == i);
    }
    node_free(test);
    ck_assert_int_eq(res, 4);
}
END_TEST

Suite *calc_node_suite(void)
{
    Suite *s;
    TCase *pos;
    TCase *neg;
    s = suite_create("node");

    pos = tcase_create("positives");
    tcase_add_test(pos, pos_node_find);
    tcase_add_test(pos, pos_push_front_test);
    tcase_add_test(pos, pos_pop_end_test);
    tcase_add_test(pos, pos_sort_test);

    neg = tcase_create("negatives");
    tcase_add_test(neg, neg_node_find_NULL_data);
    tcase_add_test(neg, neg_node_free_NULL_head);
    tcase_add_test(neg, neg_sort_NULL_head_test);

    suite_add_tcase(s, neg);
    suite_add_tcase(s, pos);
    return s;
}
