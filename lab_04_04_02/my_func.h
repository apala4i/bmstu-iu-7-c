#include <string.h>
#define DATE 1
#define NOT_DATE 0
#define JANUARY 1
#define FEBRUARY 8
#define MARCH 2
#define APRIL 12
#define MAY 3
#define JUNE 10
#define JULY 4
#define AUGUST 5
#define SEPTEMBER 9
#define OCTOBER 6
#define NOVEMBER 11
#define DECEMBER 7
#define NOT_A_MONTH 100
#define MAX_MONTH_LEN 9
#define LEAP 1
#define NOT_LEAP 0

int leap_check(const int year)
{
    if (!(year % 400))
        return LEAP;
    if (year % 4 == 0)
        if (year % 100 != 0)
            return LEAP;
    return NOT_LEAP;
}

int month_num(const char *month)
{
    if (!strcmp(month, "january"))
        return JANUARY;
    else if (!strcmp(month, "february"))
        return FEBRUARY;
    else if (!strcmp(month, "march"))
        return MARCH;
    else if (!strcmp(month, "april"))
        return APRIL;
    else if (!strcmp(month, "may"))
        return MAY;
    else if (!strcmp(month, "june"))
        return JUNE;
    else if (!strcmp(month, "july"))
        return JULY;
    else if (!strcmp(month, "august"))
        return AUGUST;
    else if (!strcmp(month, "september"))
        return SEPTEMBER;
    else if (!strcmp(month, "october"))
        return OCTOBER;
    else if (!strcmp(month, "november"))
        return NOVEMBER;
    else if (!strcmp(month, "december"))
        return DECEMBER;
    else
        return NOT_A_MONTH;
}

int legit_check_date(char *string)
{
    // date catching

    //sign catching
    for (int i = 0; i < strlen(string); i++)
        if (string[i] == '+')
            return NOT_DATE;

    char *pend;
    int date = strtol(string, &pend, 10);
    if (!date || date > 31 || date <= 0)
    {
        return NOT_DATE;
    }

    // intersection check
    if (!strchr(" 0\n\t\v\f\r", *pend))
        return NOT_DATE;

    while (strchr(" \n\t\v\f\r", *pend))
        pend++;

    // month catching
    char month[10];
    int count = 0;

    while (!strchr(" 0\n\t\v\f\r", *pend))
    {
        month[count++] = *pend;
        pend++;
        if (count > MAX_MONTH_LEN)
        {
            return NOT_DATE;
        }
    }
    if (!count)
    {
        return NOT_DATE;
    }
    month[count] = 0;

    // year catching
    int year = strtol(pend, &pend, 10);
    if (year >= 10000 || year <= 0)
    {
        return NOT_DATE;
    }

    // other digit check
    for (int i = 0; i < strlen(pend); i++)
    {
        if (!isspace(pend[i]))
            return NOT_DATE;
    }

    // month lower
    for (int i = 0; i < count; i++)
        month[i] = tolower(month[i]);

    // month and date analyse
    int month_type = month_num(month);
    if (month_type == NOT_A_MONTH)
        return NOT_DATE;
    if (month_type <= 7)
        date -= 1;
    if (month_type == FEBRUARY)
    {
        if (date > 29)
        {
            return NOT_DATE;
        }
        if (date == 29)
            if (!leap_check(year))
            {
                return NOT_DATE;
            }
    }
    if (date > 30)
    {
        return NOT_DATE;
    }
    return DATE;
}