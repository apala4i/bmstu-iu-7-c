#include <check.h>
#include "errors.h"
#include <stdlib.h>
#include "my_snprintf.h"

// s check
START_TEST(pos_str_all_without_extra_check)
{
    char first_buf[80];
    char second_buf[80];
    char letter[] = "hello";
    int max_len = 20;
    int my_res, real_res;
    my_res = my_snprintf(first_buf, max_len, "%s", letter);
    real_res = snprintf(second_buf, max_len, "%s", letter);
    ck_assert_str_eq(first_buf, second_buf);
    ck_assert_int_eq(my_res, real_res);
}
END_TEST

START_TEST(pos_str_all_with_extra_check)
    {
        char first_buf[80];
        char second_buf[80];
        char letter[] = "hello";
        int max_len = 20;
        int my_res, real_res;
        my_res = my_snprintf(first_buf, max_len, "asd%sasd", letter);
        real_res = snprintf(second_buf, max_len, "asd%sasd", letter);
        ck_assert_str_eq(first_buf, second_buf);
        ck_assert_int_eq(my_res, real_res);
    }
END_TEST

START_TEST(pos_str_piece_with_extra_check)
    {
        char first_buf[80];
        char second_buf[80];
        char letter[] = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhh";
        int max_len = 20;
        int my_res, real_res;
        my_res = my_snprintf(first_buf, max_len, "asd%sasd", letter);
        real_res = snprintf(second_buf, max_len, "asd%sasd", letter);
        ck_assert_str_eq(first_buf, second_buf);
        ck_assert_int_eq(my_res, real_res);
    }
END_TEST

START_TEST(pos_str_piece_without_extra_check)
    {
        char first_buf[80];
        char second_buf[80];
        char letter[] = "helloooooooooooasdfasdfasdfasdfasdfasdf";
        int max_len = 20;
        int my_res, real_res;
        my_res = my_snprintf(first_buf, max_len, "%s", letter);
        real_res = snprintf(second_buf, max_len, "%s", letter);
        ck_assert_str_eq(first_buf, second_buf);
        ck_assert_int_eq(my_res, real_res);
    }
END_TEST

START_TEST(pos_str_all_before_extra_check)
    {
        char first_buf[80];
        char second_buf[80];
        char letter[] = "hello";
        int max_len = 20;
        int my_res, real_res;
        my_res = my_snprintf(first_buf, max_len, "asd%s", letter);
        real_res = snprintf(second_buf, max_len, "asd%s", letter);
        ck_assert_str_eq(first_buf, second_buf);
        ck_assert_int_eq(my_res, real_res);
    }
END_TEST

START_TEST(pos_str_all_after_extra_check)
    {
        char first_buf[80];
        char second_buf[80];
        char letter[] = "hello";
        int max_len = 20;
        int my_res, real_res;
        my_res = my_snprintf(first_buf, max_len, "%sasd", letter);
        real_res = snprintf(second_buf, max_len, "%sasd", letter);
        ck_assert_str_eq(first_buf, second_buf);
        ck_assert_int_eq(my_res, real_res);
    }
END_TEST

START_TEST(pos_str_piece_before_extra_check)
    {
        char first_buf[80];
        char second_buf[80];
        char letter[] = "hello";
        int max_len = 12;
        int my_res, real_res;
        my_res = my_snprintf(first_buf, max_len, "asdasdasd%s", letter);
        real_res = snprintf(second_buf, max_len, "asdasdasd%s", letter);
        ck_assert_str_eq(first_buf, second_buf);
        ck_assert_int_eq(my_res, real_res);
    }
END_TEST

// hd check
START_TEST(pos_hd_all_without_extra_check)
    {
        char first_buf[80];
        char second_buf[80];
        short int digit = 12;
        int max_len = 20;
        int my_res, real_res;
        my_res = my_snprintf(first_buf, max_len, "%hd", digit);
        real_res = snprintf(second_buf, max_len, "%hd", digit);
        ck_assert_str_eq(first_buf, second_buf);
        ck_assert_int_eq(my_res, real_res);
    }
END_TEST

START_TEST(pos_hd_all_with_extra_check)
    {
        char first_buf[80];
        char second_buf[80];
        short int digit = 30;
        int max_len = 20;
        int my_res, real_res;
        my_res = my_snprintf(first_buf, max_len, "asd%hdasd", digit);
        real_res = snprintf(second_buf, max_len, "asd%hdasd", digit);
        ck_assert_str_eq(first_buf, second_buf);
        ck_assert_int_eq(my_res, real_res);
    }
END_TEST

START_TEST(pos_hd_piece_with_extra_check)
    {
        char first_buf[80];
        char second_buf[80];
        short int digit = -120;
        int max_len = 8;
        int my_res, real_res;
        my_res = my_snprintf(first_buf, max_len, "asdasd%hd", digit);
        real_res = snprintf(second_buf, max_len, "asdasd%hd", digit);
        ck_assert_str_eq(first_buf, second_buf);
        ck_assert_int_eq(my_res, real_res);
    }
END_TEST

START_TEST(pos_hd_piece_without_extra_check)
    {
        char first_buf[80];
        char second_buf[80];
        short int digit = -120;
        int max_len = 2;
        int my_res, real_res;
        my_res = my_snprintf(first_buf, max_len, "%hd", digit);
        real_res = snprintf(second_buf, max_len, "%hd", digit);
        ck_assert_str_eq(first_buf, second_buf);
        ck_assert_int_eq(my_res, real_res);
    }
END_TEST

START_TEST(pos_hd_all_before_extra_check)
    {
        char first_buf[80];
        char second_buf[80];
        short int digit = 12;
        int max_len = 20;
        int my_res, real_res;
        my_res = my_snprintf(first_buf, max_len, "asd%hd", digit);
        real_res = snprintf(second_buf, max_len, "asd%hd", digit);
        ck_assert_str_eq(first_buf, second_buf);
        ck_assert_int_eq(my_res, real_res);
    }
END_TEST

START_TEST(pos_hd_all_after_extra_check)
    {
        char first_buf[80];
        char second_buf[80];
        short int digit = 12;
        int max_len = 20;
        int my_res, real_res;
        my_res = my_snprintf(first_buf, max_len, "%hdasd", digit);
        real_res = snprintf(second_buf, max_len, "%hdasd", digit);
        ck_assert_str_eq(first_buf, second_buf);
        ck_assert_int_eq(my_res, real_res);
    }
END_TEST

START_TEST(pos_hd_all_neg_check)
    {
        char first_buf[80];
        char second_buf[80];
        short int digit = -12;
        int max_len = 20;
        int my_res, real_res;
        my_res = my_snprintf(first_buf, max_len, "%hd", digit);
        real_res = snprintf(second_buf, max_len, "%hd", digit);
        ck_assert_str_eq(first_buf, second_buf);
        ck_assert_int_eq(my_res, real_res);
    }
END_TEST

START_TEST(neg_empty_str)
    {
        char first_buf[80];
        char second_buf[80];
        char letter[] = "";
        int max_len = 20;
        int my_res, real_res;
        my_res = my_snprintf(first_buf, max_len, "%s", letter);
        real_res = snprintf(second_buf, max_len, "%s", letter);
        ck_assert_str_eq(first_buf, second_buf);
        ck_assert_int_eq(my_res, real_res);
    }
END_TEST

START_TEST(neg_null_str)
    {
        char *first_buf = NULL;
        char *second_buf = NULL;
        char letter[] = "";
        int max_len = 0;
        int my_res, real_res;
        my_res = my_snprintf(first_buf, max_len, "%s", letter);
        real_res = snprintf(second_buf, max_len, "%s", letter);
        ck_assert_int_eq(my_res, real_res);
    }
END_TEST

START_TEST(neg_zero_str)
    {
        char first_buf[80] = "check";
        char second_buf[80] = "check";
        char letter[] = "asd";
        int max_len = 0;
        int my_res, real_res;
        my_res = my_snprintf(first_buf, max_len, "%s", letter);
        real_res = snprintf(second_buf, max_len, "%s", letter);
        ck_assert_str_eq(first_buf, second_buf);
        ck_assert_int_eq(my_res, real_res);
    }
END_TEST



//START_TEST(neg_empty_hd)
//    {
//        char first_buf[80];
//        char second_buf[80];
//        short int digit = 0;
//        int max_len = 20;
//        int my_res, real_res;
//        my_res = my_snprintf(first_buf, max_len, "%hd", digit);
//        real_res = my_snprintf(second_buf, max_len, "%hd", digit);
//        ck_assert_str_eq(first_buf, second_buf);
//        ck_assert_int_eq(my_res, real_res);
//    }
//END_TEST

Suite *calc_node_suite(void)
{
    Suite *s;
    TCase *pos;
    TCase *neg;
    s = suite_create("node");

    pos = tcase_create("positives");
    tcase_add_test(pos, pos_str_all_after_extra_check);
    tcase_add_test(pos, pos_str_all_before_extra_check);
    tcase_add_test(pos, pos_str_all_with_extra_check);
    tcase_add_test(pos, pos_str_all_without_extra_check);
    tcase_add_test(pos, pos_str_piece_before_extra_check);
    tcase_add_test(pos, pos_str_piece_with_extra_check);
    tcase_add_test(pos, pos_str_piece_without_extra_check);

    tcase_add_test(pos, pos_hd_all_after_extra_check);
    tcase_add_test(pos, pos_hd_all_before_extra_check);
    tcase_add_test(pos, pos_hd_all_neg_check);
    tcase_add_test(pos, pos_hd_all_with_extra_check);
    tcase_add_test(pos, pos_hd_all_without_extra_check);
    tcase_add_test(pos, pos_hd_piece_with_extra_check);
    tcase_add_test(pos, pos_hd_piece_without_extra_check);

    neg = tcase_create("negatives");
    tcase_add_test(neg, neg_empty_str);
    tcase_add_test(neg, neg_null_str);
    tcase_add_test(neg, neg_zero_str);

    suite_add_tcase(s, neg);
    suite_add_tcase(s, pos);
    return s;
}