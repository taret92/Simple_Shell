#include "main.h"
/**
 * main - shell
 * @argc - number of arguments
 * @argv - arguments
 * @envp - environment
 * Return: Success!
 */
int main(void)
{
	char **tokens = NULL, *str = NULL;
	int i = 0, tty = 1;

	command_t built_ins[] = {{"exit", exe_exit},
							 {NULL, NULL}};
	signal(SIGINT, ctrl_c);
	if (isatty(STDIN_FILENO) == 0)
		tty = 0;
	do
	{
		if (tty == 1)
			write(STDOUT_FILENO, "($) ", 4);
		fflush(stdin);
		str = line_read();
		tokens = _strtok(tokens, str, " \t\n");
		for (i = 0; built_ins[i].name; i++)
		{
			if (built_ins[i].name == tokens[0])
			{
				if ((built_ins[i].function(tokens)) == 1)
					return (EXIT_SUCCESS);
			}
		}
		if (!tokens[0])
		{
			free(tokens);
			free(str);
			continue;
		}
		if (tokens[0][0] == '/')
			execute(tokens);
		else
		{
			tokens[0] = PATH(tokens[0]);
			(tokens[0] != NULL ? execute(tokens) : perror("Error"));
		}
	} while (1);
	free(tokens);
	return (0);
}

/**
 * line_read - get the line
 * Return: str
 */
char *line_read(void)
{
	int getline2;
	size_t j = 0;
	char *str = NULL;

	getline2 = getline(&str, &j, stdin);
	if (getline2 == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("get_line");
			exit(EXIT_FAILURE);
		}
		free(str);
	}
	return (str);
}
