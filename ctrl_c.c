#include "main.h"
/**
 * ctrl_c - Function to exit
 * @sig: Variable type integer to next function
 */
void ctrl_c(int sig)
{
	(void)sig;
	_putchar('\n');
	write(STDOUT_FILENO, SIGN_S, _strlen(SIGN_S));
}
