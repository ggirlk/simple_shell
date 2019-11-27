#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "holberton.h"

/**
 * hsh_env - prints the environment.
 * @a: List of args.  Not examined
 * @p: the name of the executable program
 * Return: 1 on success, -1 on fail
 */

int hsh_env(char **a __attribute__((unused)), char *p __attribute__((unused)))
{
int i, n;
for (i = 0; environ[i] != NULL; i++)
{
n = write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
if (n == -1)
return (-1);

write(STDOUT_FILENO, "\n", 1);
}
return (1);
}
