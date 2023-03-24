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
    int days_in_feb = 28;

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        days_in_feb = 29;
    }

    if (month > 2 && days_in_feb == 28)
    {
        day--;
    }

    switch (month)
    {
        case 1:
            day = 31 + day;
            break;
        case 2:
            day = 31 + day;
            break;
        case 3:
            day = 59 + day;
            break;
        case 4:
            day = 90 + day;
            break;
        case 5:
            day = 120 + day;
            break;
        case 6:
            day = 151 + day;
            break;
        case 7:
            day = 181 + day;
            break;
        case 8:
            day = 212 + day;
            break;
        case 9:
            day = 243 + day;
            break;
        case 10:
            day = 273 + day;
            break;
        case 11:
            day = 304 + day;
            break;
        case 12:
            day = 334 + day;
            break;
        default:
            break;
    }

    printf("Day of the year: %d\n", day);
    printf("Remaining days: %d\n", 365 + (days_in_feb == 29) - day);
}

