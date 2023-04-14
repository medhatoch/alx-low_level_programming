#include <stdlib.h>
#include <stdio.h>

/**
 * _isdigit - checks if a character is a digit
 * @c: the character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * mul - multiplies two numbers represented as arrays of digits
 * @num1: the first number
 * @len1: the length of the first number
 * @num2: the second number
 * @len2: the length of the second number
 *
 * Return: a pointer to an array of digits containing the result of the
 * multiplication
 */
char *mul(char *num1, int len1, char *num2, int len2)
{
	int i, j, n, carry;
	char *res;

	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);

	for (i = 0; i < len1 + len2; i++)
		res[i] = '0';
	res[len1 + len2] = '\0';

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			n = (num1[i] - '0') * (num2[j] - '0') +
				(res[i + j + 1] - '0') + carry;
			carry = n / 10;
			res[i + j + 1] = (n % 10) + '0';
		}
		res[i] += carry;
	}

	i = 0;
	while (res[i] == '0' && i < len1 + len2 - 1)
		i++;
	return (res + i);
}

/**
 * main - multiplies two positive numbers
 * @argc: the number of arguments
 * @argv: the arguments vector
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	char *num1, *num2, *result;
	int len1, len2, i, j;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	for (i = 1; i < 3; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (!_isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (98);
			}
		}
	}

	num1 = argv[1];
	num2 = argv[2];
	len1 = 0;
	while (num1[len1])
		len1++;
	len2 = 0;
	while (num2[len2])
		len2++;

	result = mul(num1, len1, num2, len2);
	printf("%s\n", result);
	free(result);
	return (0);
}
