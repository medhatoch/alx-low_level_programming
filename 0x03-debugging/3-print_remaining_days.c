#include <stdio.h>
#include "main.h"

/**
* print_remaining_days - takes a date and prints how many days are
* left in the year, taking leap years into account
* @month: month in number format
* @day: day of month
* @year: year
* Return: void
*/
void print_remaining_days(int month, int day, int year)
{
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, total_days = 0;

    for (i = 1; i < month; i++) {
        total_days += days_in_month[i];
    }

    total_days += day;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        if (month > 2) {
            total_days += 1;
        }

        printf("Day of the year: %d\n", total_days);
        printf("Remaining days: %d\n", 366 - total_days);
    } else {
        printf("Day of the year: %d\n", total_days);
        printf("Remaining days: %d\n", 365 - total_days);
    }
}

