#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"
/**
 * hsh_exit - builtin command: exit.
 * @a: list of args.  Not examined.
 * @p: the name of the executable program
 * Return: Always returns 0, to terminate execution.
 */
int hsh_exit(char **a, char *p __attribute__((unused)))
{
int status;
if (a[1])
{
status = _atoi(a[1]);
exit(status);
}
else
exit(0);
return (1);
}
