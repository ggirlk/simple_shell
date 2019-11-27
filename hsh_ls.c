#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "holberton.h"

/**
 * hsh_ls - shows the contents of a directory.
 * @args: List of args.
 * @progname: the name of the executable program
 * Return: 1
 */
int hsh_ls(char **args, char *progname)
{
int  i;
char **newargs = malloc(sizeof(args));
if (args)
{
newargs[0] = "/bin/ls";
for (i = 0; args[i] != NULL; i++)
{
newargs[i + 1] = args[i + 1];
}
return (hsh_launch(newargs, progname));
}
return (1);
}
