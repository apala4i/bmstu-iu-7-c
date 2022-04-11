#include "stdio.h"
#include "string.h"
#include "ctype.h"

// return values
#define FILE_DOES_NOT_EXIST 1 /// error appears in functions when openning file does not exist
#define STABLE_WORK 0 /// appears in functions if function have been worked correctly
#define TOO_SHORT_SURNAME 2
#define NOT_FOUND 3
#define GOOD_SURNAME 0
#define BAD_SURNAME 1
#define NOT_NUM 5
#define NUM 6

// consts
#define MAX_SURNAME_LEN 20
#define MAX_NUMBER_LEN 11


typedef struct {
    char surname[MAX_SURNAME_LEN + 2];
    char number[MAX_NUMBER_LEN + 2];
} subscriber;

int name_check(char surname[]);
int num_checker(char num[]);