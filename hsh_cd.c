#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "holberton.h"

/**
 * hsh_cd - builtin command: change directory.
 * @args: List of args.  args[0] is "cd".  args[1] is the directory.
 * @progname: the name of the executable program
 * Return: Always returns 1, to continue executing.
 */
int hsh_cd(char **args, char *progname)
{
if (args[1] == NULL)
{
write(STDOUT_FILENO, progname, _strlen(progname));
write(STDOUT_FILENO, ": expected argument to \"cd\"\n", 31);
}
else
{
if (chdir(args[1]) != 0)
{
perror(progname);
}
}
return (1);
}
