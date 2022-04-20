#include "main.h"
/**
 * _strtok - tokens the string.
 * @tokens: Array contains the tokens.
 * @str: string.
 * @delim: delimiter
 * Return: tokens.
 */

char **_strtok(char **tokens, char *str, char *delim)
{
	char *token2 = NULL;
	int i = 0;

	tokens = malloc(1024 * sizeof(char *));
	if (tokens == NULL)
	{
		free(tokens);
		free(str);
		return (NULL);
	}
	token2 = strtok(str, delim);
	while (token2 != NULL)
	{
		tokens[i] = token2;
		i++;
		token2 = strtok(NULL, delim);
	}
	token2 = NULL;
	tokens[i] = NULL;
	free(token2);
	return (tokens);
}

/**
 * exe_exit - built in function for exit
 * @args: arguments
 * Return: 1
 */

int exe_exit(char **tokens)
{
	(void)(tokens);

	return (EXIT_SUCCESS);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - Counts the lenght of string
 *
 *
 * @s: Input string
 *
 * Return: Returns the value of the lenght var
 *
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);
}

/**
 * _strcat - Print characters
 * @dest: Input string 1
 * @src: Input string 2
 * Return: Concatenated strings
 */

char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;
	while (*src)
		*p++ = *src++;
	*p = '\0';
	return (dest);
}
