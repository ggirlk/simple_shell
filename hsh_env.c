#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "holberton.h"

/**
 * env - prints the environment.
 * @args: List of args.  Not examined
 * Return: 1 on success, -1 on fail
 */
extern char **environ;
int hsh_env(char **args __attribute__((unused)), char *progname __attribute__((unused)))
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
