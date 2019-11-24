#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "holberton.h"

/**
 * hsh_ls - shows the contents of a directory.
 * @args: List of args.
 * Return: 1
 */
int hsh_ls(char **args)
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
return (hsh_launch(newargs));
}
return (1);
}
