#include "shell.h"

/**
 * **strngthow - Splits a string into words.
 * @str: The input string to be split.
 * @d: The delimiter string used to determine word boundaries.
 * Return: A pointer to an array of strings or NULL on failure.
 * tokenizer.c
 */

char **strngthow(char *str, char *d)
{
	int word_cnt = 0;
	int x, j, k, m;
	char **s;

	if (!str || str[0] == 0)
		return (NULL);
	if (d == NULL)
		d = " ";
	for (x = 0; str[x] != '\0'; x++)
		if (!delimiter(str[x], d) && (delimiter(str[x + 1], d) || !str[x + 1]))
			word_cnt++;

	if (word_cnt == 0)
		return (NULL);
	s = malloc((1 + word_cnt) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, j = 0; j < word_cnt; j++)
	{
		while (delimiter(str[x], d))
			x++;
		k = 0;
		while (!delimiter(str[x + k], d) && str[x + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
			{
				free(s[k]);
			}
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[x++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}


/**
 * **strngthow2 - Splits a string into words.
 * @str: The input string to be split.
 * @d: The delimiter string used to determine word boundaries.
 * Return: A pointer to an array of strings or NULL on failure.
 * tokenizer.c
 */
char **strngthow2(char *str, char d)
{
	int x, j, k, m, word_cnt;
	char **s;

	 word_cnt = 0;
	if (!str || str[0] == 0)
		return (NULL);
	for (x = 0; str[x] != '\0'; x++)
		if ((str[x] != d && str[x + 1] == d) ||
		    (str[x] != d && !str[x + 1]) || str[x + 1] == d)
			word_cnt++;
	if (word_cnt == 0)
		return (NULL);
	s = malloc((1 + word_cnt) * sizeof(char *));
	if (s == NULL)
		return (NULL);
	for (x = 0, j = 0; j < word_cnt; j++)
	{
		while (str[x] == d && str[x] != d)
			x++;
		k = 0;
		while (str[x + k] != d && str[x + k] && str[x + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[x++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
