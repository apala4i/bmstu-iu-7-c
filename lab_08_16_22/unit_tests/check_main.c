#include "check_header.h"

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

//    s = calc_matrix_sum_suite();
//
//    runner = srunner_create(s);
//
//    srunner_run_all(runner, CK_VERBOSE);
//    no_failed = srunner_ntests_failed(runner);
//    srunner_free(runner);
//
//    s = calc_matrix_mul_suite();
//    runner = srunner_create(s);
//    srunner_run_all(runner, CK_VERBOSE);
//    no_failed = srunner_ntests_failed(runner);
//    srunner_free(runner);

    s = calc_matrix_det_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}