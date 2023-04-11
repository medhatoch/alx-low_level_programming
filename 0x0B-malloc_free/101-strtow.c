#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts the number of words in a string.
 * @str: the input string.
 *
 * Return: the number of words.
 */
int count_words(char *str)
{
	int i, count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			count++;
	}

	return (count);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 * @str: the input string.
 *
 * Return: a pointer to the duplicated string, or NULL if it fails.
 */
char *_strdup(char *str)
{
	char *dup;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		dup[i] = str[i];

	dup[len] = '\0';
	return (dup);
}

/**
 * strtow - splits a string into words.
 * @str: the input string.
 *
 * Return: a pointer to an array of strings (words), or NULL if it fails.
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, n;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	n = count_words(str);
	words = malloc(sizeof(char *) * (n + 1));
	if (words == NULL)
		return (NULL);

	for (i = 0, j = 0; i < n; i++)
	{
		while (str[j] == ' ')
			j++;

		k = j;
		while (str[j] && str[j] != ' ')
			j++;

		words[i] = _strdup(str + k);
		if (words[i] == NULL)
		{
			for (i--; i >= 0; i--)
				free(words[i]);
			free(words);
			return (NULL);
		}
	}

	words[i] = NULL;
	return (words);
}
