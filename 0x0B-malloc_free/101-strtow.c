#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * strtow - Splits a string into words.
 *
 * @str: String to split.
 *
 * Return: Pointer to an array of strings (words).
 * NULL if str == NULL or str == "" or if the function fails.
 */

char **strtow(char *str)
{
	int i, j, k, n_words = 0, len = 0;
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);

	len = strlen(str);

	for (i = 0; i < len; i++)
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			n_words++;

	words = malloc(sizeof(char *) * (n_words + 1));

	if (words == NULL)
		return (NULL);

	j = 0;

	for (i = 0; i < len; i++)
	{
		if (str[i] != ' ')
		{
			k = i;

			while (str[k] != ' ' && str[k] != '\0')
				k++;

			words[j] = malloc(sizeof(char) * (k - i + 1));

			if (words[j] == NULL)
			{
				for (j = j - 1; j >= 0; j--)
					free(words[j]);

				free(words);
				return (NULL);
			}

			strncpy(words[j], &str[i], k - i);
			words[j][k - i] = '\0';
			j++;
			i = k;
		}
	}

	words[n_words] = NULL;

	return (words);
}
