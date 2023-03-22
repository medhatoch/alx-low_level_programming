#include "main.h"
/**
 * jack_bauer - prints every minute of the day of Jack Bauer
 */
void jack_bauer(void)
{
int hours, minutes;

/* Loop over all hours and minutes in the day */
for (hours = 0; hours < 24; hours++)
{
for (minutes = 0; minutes < 60; minutes++)
{
/* Print the current time */
_putchar((hours / 10) + '0');
_putchar((hours % 10) + '0');
_putchar(':');
_putchar((minutes / 10) + '0');
_putchar((minutes % 10) + '0');
_putchar('\n');
}
}
}
