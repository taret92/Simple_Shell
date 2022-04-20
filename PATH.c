#include "main.h"

/**
 * PATH - search the commands in path
 * @comm: Commands
 * Return: 0
 */

char *PATH(char *comm)
{
	char *dup = NULL;
	char **env = environ;
	char **funclist = malloc(102450 * sizeof(char *)), *funcs = NULL;
	struct stat stats;
	int count = 0, i = 0;

	for (count = 0; env[count] != NULL; count++)
	{
		if ((strncmp("PATH", env[count], sizeof(5000))) == 0)
			break;
	}
	dup = strdup(env[count]);
	funcs = strtok(dup, ":=");
	while (funcs != NULL)
	{
		funclist[i] = strdup(funcs);
		_strcat(funclist[i], "/");
		_strcat(funclist[i], comm);
		if (stat(funclist[i], &stats) == 0)
		{
			free(dup);
			return (funclist[i]);
		}
		free(funclist[i]);
		i++;
		funcs = strtok(NULL, ":");
	}
	free(funclist[i]);
	free(funclist);
	free(dup);
	return (NULL);
}
